/*
** calc.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 18 18:56:11 2015 marc brout
** Last update Fri Dec 25 00:57:53 2015 marc brout
*/

#include "wolf.h"

void		basic_to_sec(t_param *arg, int x)
{
  arg->calc.xf = arg->calc.d;
  arg->calc.yf = arg->wm.ydep[x];
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
      arg->calc.xf = arg->lvl[arg->curlvl].playerx + arg->calc.vecx *
	arg->calc.k;
      arg->calc.x = 1;
      if (arg->lvl[arg->curlvl].map[(int)arg->calc.yf][(int)arg->calc.xf])
	return ;
      arg->calc.yf = arg->lvl[arg->curlvl].playery + arg->calc.vecy *
	arg->calc.k;
      arg->calc.x = 0;
      if (arg->lvl[arg->curlvl].map[(int)arg->calc.yf][(int)arg->calc.xf])
	return ;
      if ((int)arg->calc.xf <= 0 ||
	  (int)arg->calc.xf >= arg->lvl[arg->curlvl].width ||
	  (int)arg->calc.yf <= 0 ||
	  (int)arg->calc.yf >= arg->lvl[arg->curlvl].height)
	return ;
    }
}

void		project_k(t_param *arg, t_lvl *lvl, int x)
{
  int		y;
  t_color	*pixels;
  int		total;

  pixels = arg->pix->pixels;
  total = (HEIGHT / 2) + HEIGHT / (2 * arg->calc.k) + lvl->yangle;
  y = (HEIGHT / 2) - HEIGHT / (2 * arg->calc.k) - 1 + lvl->yangle;
  y = (y >= 0) ? y : -1;
  if (lvl->map[(int)arg->calc.yf][(int)arg->calc.xf] == 3)
    while (++y < total && y < HEIGHT)
      pixels[x + y * WIDTH].full = GREEN;
  else if (lvl->map[(int)arg->calc.yf][(int)arg->calc.xf] == 4)
    while (++y < total && y < HEIGHT)
      pixels[x + y * WIDTH].full = RED;
  else
    {
      wall_north_east(arg, x, y, total);
      wall_north_west(arg, x, y, total);
      wall_south_west(arg, x, y, total);
      wall_south_east(arg, x, y, total);
    }
}

void		calc_walls(t_param *arg)
{
  int		x;

  x = -1;
  while (++x < WIDTH)
    {
      basic_to_sec(arg, x);
      get_len(arg);
      project_k(arg, &arg->lvl[arg->curlvl], x);
    }
}
