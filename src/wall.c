/*
** wall.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 25 00:46:23 2015 marc brout
** Last update Fri Dec 25 01:53:00 2015 marc brout
*/

#include "wolf.h"

void		wall_north_east(t_param *arg, int x, int y, int total)
{
  unsigned int	*pixels;

  pixels = arg->pix->pixels;
  if (arg->calc.vecx >= 0 && arg->calc.vecy >= 0)
    {
      if (arg->calc.x)
  	while (++y < total && y < HEIGHT)
  	  pixels[x + y * WIDTH] = WALLA;
      else
  	while (++y < total && y < HEIGHT)
  	  pixels[x + y * WIDTH] = WALLB;
    }
}

void		wall_north_west(t_param *arg, int x, int y, int total)
{
  unsigned int	*pixels;

  pixels = arg->pix->pixels;
  if (arg->calc.vecx < 0 && arg->calc.vecy >= 0)
    {
      if (arg->calc.x)
  	while (++y < total && y < HEIGHT)
  	  pixels[x + y * WIDTH] = WALLD;
      else
  	while (++y < total && y < HEIGHT)
  	  pixels[x + y * WIDTH] = WALLB;
    }
}

void		wall_south_west(t_param *arg, int x, int y, int total)
{
  unsigned int	*pixels;

  pixels = arg->pix->pixels;
  if (arg->calc.vecx < 0 && arg->calc.vecy < 0)
    {
      if (arg->calc.x)
  	while (++y < total && y < HEIGHT)
  	  pixels[x + y * WIDTH] = WALLD;
      else
  	while (++y < total && y < HEIGHT)
  	  pixels[x + y * WIDTH] = WALLC;
    }
}

void		wall_south_east(t_param *arg, int x, int y, int total)
{
  unsigned int	*pixels;

  pixels = arg->pix->pixels;
  if (arg->calc.vecx >= 0 && arg->calc.vecy < 0)
    {
      if (arg->calc.x)
  	while (++y < total && y < HEIGHT)
  	  pixels[x + y * WIDTH] = WALLA;
      else
  	while (++y < total && y < HEIGHT)
  	  pixels[x + y * WIDTH] = WALLC;
    }
}
