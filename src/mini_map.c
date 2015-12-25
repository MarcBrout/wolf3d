/*
** mini_map.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Dec 21 16:32:47 2015 marc brout
** Last update Thu Dec 24 14:36:11 2015 marc brout
*/

#include "wolf.h"

char		mal_mini_map(t_param *arg, t_lvl *lvl)
{
  if ((lvl->mini = bunny_new_pixelarray(arg->calc.mini * (lvl->width + 10),
					arg->calc.mini * (lvl->height + 10)))
      == NULL)
    return (1);
  return (0);
}

void		set_lvl_minimap(t_param *arg, t_lvl *lvl)
{
  int		i;
  int		total;
  t_color	*pixels;

  pixels = lvl->mini->pixels;
  i = -1;
  total = lvl->mini->clipable.clip_height * lvl->mini->clipable.clip_width;
  while (++i < total)
    pixels[i].full = SKY;
  set_bump(arg, lvl);
}

void		set_minimaps(t_param *arg)
{
  int		i;

  i = -1;
  while (++i < arg->nblvl)
    set_lvl_minimap(arg, &arg->lvl[i]);
}

void		tek_circle(t_lvl *lvl, int x)
{
  t_color	*pixels;

  pixels = lvl->mini->pixels;
  pixels[x].full = PLAYER;
  pixels[x - 1].full = PLAYER;
  pixels[x + 1].full = PLAYER;
  pixels[x + lvl->mini->clipable.clip_width].full = PLAYER;
  pixels[x - lvl->mini->clipable.clip_width].full = PLAYER;
  pixels[x + 1 - lvl->mini->clipable.clip_width].full = PLAYER;
  pixels[x + 1 + lvl->mini->clipable.clip_width].full = PLAYER;
  pixels[x - 1 + lvl->mini->clipable.clip_width].full = PLAYER;
  pixels[x - 1 - lvl->mini->clipable.clip_width].full = PLAYER;
}

void		add_player_to_mini(t_param *arg, t_lvl *lvl)
{
  int		x;
  int		y;

  x = lvl->playerx * arg->calc.mini;
  y = (lvl->height - lvl->playery) * arg->calc.mini;
  lvl->minipos = x + 5 * arg->calc.mini + ((y + 5 * arg->calc.mini) *
					   lvl->mini->clipable.clip_width);
  tek_circle(lvl, lvl->minipos);
}
