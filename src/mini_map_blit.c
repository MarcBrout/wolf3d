/*
** mini_map_blit.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec 22 01:06:18 2015 marc brout
** Last update Tue Dec 22 17:05:46 2015 marc brout
*/

#include "wolf.h"

void		set_bump(t_lvl *lvl)
{
  int		x;
  int		y;
  int		xmax;
  int		ymax;
  t_color	*pixels;

  pixels = lvl->mini->pixels;
  y = MINI * 5 - 1;
  ymax = y + 1 + MINI * lvl->height;
  xmax = MINI * (lvl->width + 5);
  while (++y < ymax)
    {
      x = MINI * 5 - 1;
      while (++x < xmax)
	{
	  if (lvl->map[lvl->height - 1 - ((y - 5 * MINI) / MINI)]
	      [(x - 5 * MINI) / MINI])
	    pixels[x + y * lvl->mini->clipable.clip_width].full = WALL;
	  else
	    pixels[x + y * lvl->mini->clipable.clip_width].full = FLOOR;
	}
    }
}

void		mini_map(t_param *arg, t_lvl *lvl)
{
  int		x;
  int		y;
  int		xmini;
  int		xmax;
  int		ymini;
  int		ymax;
  unsigned int	*pixmap;
  unsigned int	*minmap;

  y = HEIGHT - 9 * MINI - 1;
  ymini = lvl->minipos / lvl->mini->clipable.clip_width - 4 * MINI - 1;
  ymax = lvl->minipos / lvl->mini->clipable.clip_width + 4 * MINI;
  xmax = lvl->minipos % lvl->mini->clipable.clip_width + 4 * MINI;
  pixmap = arg->pix->pixels;
  minmap = lvl->mini->pixels;
  while (++ymini < ymax && ++y > 0)
    {
      x = MINI - 1;
      xmini = lvl->minipos % lvl->mini->clipable.clip_width - 4 * MINI - 1;
      while (++xmini < xmax && ++x > 0)
	pixmap[x + y * WIDTH] =
	  minmap[xmini + ymini * lvl->mini->clipable.clip_width];
    }
}

void		put_border(t_param *arg, int pix, unsigned int color)
{
  int		x;
  int		y;
  int		xmax;
  int		ymax;
  unsigned int	*pixels;

  y = HEIGHT - 9 * MINI - pix - 1;
  ymax = HEIGHT - MINI + pix;
  xmax = 9 * MINI + pix;
  pixels = arg->pix->pixels;
  while (++y < ymax)
    {
      x = MINI - pix - 1;
      while (++x < xmax)
	pixels[x + y * WIDTH] = color;
    }
}
