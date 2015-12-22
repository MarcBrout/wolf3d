/*
** mini_map.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Dec 21 16:32:47 2015 marc brout
** Last update Tue Dec 22 01:07:44 2015 marc brout
*/

#include "wolf.h"

char		mal_mini_map(t_lvl *lvl)
{
  if ((lvl->mini = bunny_new_pixelarray(MINI * (lvl->width + 10),
					MINI * (lvl->height + 10))) == NULL)
    return (1);
  return (0);
}

void		set_lvl_minimap(t_lvl *lvl)
{
  int		i;
  int		total;
  t_color	*pixels;

  pixels = lvl->mini->pixels;
  i = -1;
  total = lvl->mini->clipable.clip_height * lvl->mini->clipable.clip_width;
  while (++i < total)
    pixels[i].full = SKY;
  set_bump(lvl);
}

void		set_minimaps(t_param *arg)
{
  int		i;

  i = -1;
  while (++i < arg->nblvl)
    set_lvl_minimap(&arg->lvl[i]);
}

void		tek_circle(t_lvl *lvl, int x)
{
  t_color	*pixels;

  pixels = lvl->mini->pixels;
  pixels[x].full = PINK;
  pixels[x - 1].full = PINK;
  pixels[x + 1].full = PINK;
  pixels[x + lvl->mini->clipable.clip_width].full = PINK;
  pixels[x - lvl->mini->clipable.clip_width].full = PINK;
  pixels[x + 1 - lvl->mini->clipable.clip_width].full = PINK;
  pixels[x + 1 + lvl->mini->clipable.clip_width].full = PINK;
  pixels[x - 1 + lvl->mini->clipable.clip_width].full = PINK;
  pixels[x - 1 - lvl->mini->clipable.clip_width].full = PINK;
}

void		add_player_to_mini(t_lvl *lvl)
{
  int		x;
  int		y;

  x = lvl->playerx * MINI;
  y = (lvl->height - lvl->playery) * MINI;
  lvl->minipos =  x + 5 * MINI + ((y + 5 * MINI) *
				  lvl->mini->clipable.clip_width);
  tek_circle(lvl, lvl->minipos);
}
