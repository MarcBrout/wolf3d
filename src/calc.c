/*
** calc.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 18 18:56:11 2015 marc brout
** Last update Tue Dec 22 01:11:09 2015 marc brout
*/

#include "wolf.h"

 void		basic_to_sec(t_param *arg, int x)
{
  arg->calc.xf = arg->calc.d;
  arg->calc.yf = (arg->calc.p * (WIDTH / 2 - x)) / WIDTH;
  arg->calc.vecx =
    arg->calc.xf * arg->wm.costab[(int)arg->lvl[arg->curlvl].plangle]
    - arg->calc.yf * arg->wm.sintab[(int)arg->lvl[arg->curlvl].plangle];
  arg->calc.vecy =
    arg->calc.xf * arg->wm.sintab[(int)arg->lvl[arg->curlvl].plangle]
    + arg->calc.yf * arg->wm.costab[(int)arg->lvl[arg->curlvl].plangle];
}

void		get_len(t_param *arg)
{
  arg->calc.k = 0;
  arg->calc.xf = arg->lvl[arg->curlvl].playerx +
    arg->calc.vecx * arg->calc.k;
  arg->calc.yf = arg->lvl[arg->curlvl].playery +
    arg->calc.vecy * arg->calc.k;
  while (!arg->lvl[arg->curlvl].map[(int)arg->calc.yf][(int)arg->calc.xf])
    {
      arg->calc.k += 0.005;
      arg->calc.xf = arg->lvl[arg->curlvl].playerx +
	arg->calc.vecx * arg->calc.k;
      arg->calc.yf = arg->lvl[arg->curlvl].playery +
	arg->calc.vecy * arg->calc.k;
    }
}

void		project_k(t_param *arg, int x)
{
  int		y;
  t_color	*pixels;

  pixels = arg->pix->pixels;
  y = (HEIGHT / 2) - HEIGHT / (2 * arg->calc.k) - 1;
  y = (y >= 0) ? y : -1;
  if ((arg->calc.xf - (int)arg->calc.xf) <
      (arg->calc.yf - (int)arg->calc.yf))
    while (++y < (HEIGHT / 2) + HEIGHT / (2 * arg->calc.k) && y < HEIGHT)
      pixels[x + y * WIDTH].full = WALL;
  else
    while (++y < (HEIGHT / 2) + HEIGHT / (2 * arg->calc.k) && y < HEIGHT)
      pixels[x + y * WIDTH].full = WALLGREY;
}

void		calc_walls(t_param *arg)
{
  int		x;

  x = -1;
  while (++x < WIDTH)
    {
      basic_to_sec(arg, x);
      get_len(arg);
      project_k(arg, x);
    }
}
