/*
** calc.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 18 18:56:11 2015 marc brout
** Last update Mon Dec 21 12:13:51 2015 marc brout
*/

#include "wolf.h"

 void		basic_to_sec(t_param *arg, int x)
{
  arg->calc.xf = arg->calc.d;
  arg->calc.yf = (arg->calc.p * (WIDTH / 2 - x)) / WIDTH;
  /* printf("calc.xf= %f\n", arg->calc.xf); */
  /* printf("calc.yf= %f\n", arg->calc.yf); */
  /* printf("calc.angle= %f\n", arg->lvl[arg->curlvl].plangle); */
  arg->calc.vecx =
    arg->calc.xf * arg->wm.costab[(int)arg->lvl[arg->curlvl].plangle]
    -
    arg->calc.yf * arg->wm.sintab[(int)arg->lvl[arg->curlvl].plangle];
  arg->calc.vecy =
    arg->calc.xf * arg->wm.sintab[(int)arg->lvl[arg->curlvl].plangle]
    +
    arg->calc.yf * arg->wm.costab[(int)arg->lvl[arg->curlvl].plangle];
  /* printf("calc.vecx= %f\n", arg->calc.vecx); */
  /* printf("calc.vecy= %f\n", arg->calc.vecy); */
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
      /* printf("calc.xf= %d\n", (int)arg->calc.xf); */
      /* printf("calc.yf= %d\n", (int)arg->calc.yf); */
      arg->calc.k += 0.001;
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
  /* printf("k=%f\n", arg->calc.k); */
  /* printf("len/2=%f\n", HEIGHT / (2 * arg->calc.k)); */
  /* printf("y=%d\n", y); */
  while (++y < (HEIGHT / 2) + HEIGHT / (2 * arg->calc.k))
    pixels[x + y * WIDTH].full = WALL;
  
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

/* void		check_angle(t_param *arg) */
/* { */
/*   if (arg->calc.ang >= 0 && arg->calc.ang < 180) */
/*     arg->calc.up = 1; */
/*   else */
/*     arg->calc.up = 0; */
/*   if (arg->calc.ang >= 90 && arg->calc.ang < 270) */
/*     arg->calc.left = 1; */
/*   else */
/*     arg->calc.left = 0; */
/* } */

 /* char			compare_coord(t_param *arg, int x) */
/* { */
/*   t_bunny_position	coord0; */
/*   t_bunny_position	coord1; */
/*   t_bunny_position	coord2; */

/*   coord0.x = (int)arg->calc.xf; */
/*   coord0.y = (int)arg->calc.yf; */
/*   coord1.x = (int)arg->calc.x_x; */
/*   coord1.y = (int)arg->calc.x_y; */
/*   coord2.x = (int)arg->calc.y_x; */
/*   coord2.y = (int)arg->calc.y_y; */
/*   x += 1; */
/*   arg->calc.vecx = vecnorm(&coord0, &coord1); */
/*   arg->calc.vecy = vecnorm(&coord0, &coord2); */
/*   printf("arg->calc.vecx = %f\n", arg->calc.vecx); */
/*   printf("arg->calc.vecy = %f\n", arg->calc.vecy); */
/*   if (arg->calc.vecx < arg->calc.vecy) */
/*     return (1); */
/*   return (0); */
/* } */

/* void		project_vecx(t_param *arg, int x) */
/* { */
/*   int		y; */
/*   double	len; */
/*   t_color	*pixels; */

/*   pixels = arg->pix->pixels; */
/*   len = (arg->lvl[arg->curlvl].tiles / (arg->calc.vecx / arg->lvl[arg->curlvl].tiles)) * arg->wm.roots[0] * arg->lvl[arg->curlvl].tiles; */
/*   printf("lenx = %f\n", len); */
/*   y = (HEIGHT / 2) - len / 2 - 1; */
/*   printf("YX = %d\n", y); */
/*   while (++y < (HEIGHT / 2 + len / 2)) */
/*     pixels[y * WIDTH + x].full = WALL;  */
/* } */

/* void		project_vecy(t_param *arg, int x) */
/* { */
/*   int		y; */
/*   double	len; */
/*   t_color	*pixels; */

/*   pixels = arg->pix->pixels; */
/*   len = (arg->lvl[arg->curlvl].tiles / (arg->calc.vecy / arg->lvl[arg->curlvl].tiles)) * arg->wm.roots[0] * arg->lvl[arg->curlvl].tiles; */
/*   printf("leny = %f\n", len); */
/*   y = (HEIGHT / 2) - len / 2 - 1; */
/*   while (++y < (HEIGHT / 2 + len / 2)) */
/*     pixels[y * WIDTH + x].full = WALL;  */
/* } */

/* void		calc_walls(t_param *arg) */
/* { */
/*   int		x; */

/*   x = -1; */
/*   while (++x < WIDTH) */
/*     { */
/*       arg->calc.xf = arg->lvl[arg->curlvl].tiles * */
/* 	arg->lvl[arg->curlvl].playerx + arg->lvl[arg->curlvl].tiles / 2; */
/*       arg->calc.yf = arg->lvl[arg->curlvl].tiles * */
/* 	arg->lvl[arg->curlvl].playery + arg->lvl[arg->curlvl].tiles / 2; */
/*       printf("test : %d\n", x); */
/*       arg->calc.ang = (x < (WIDTH / 2)) ? */
/* 	360 - (arg->lvl[arg->curlvl].plangle + arg->wm.ang[GET_X(x)]) : */
/* 	360 - (arg->lvl[arg->curlvl].plangle - arg->wm.ang[GET_X(x)]); */
/*       check_angle(arg); */
/*       /\* printf("arg->calc.ang = %f\n", arg->calc.ang); *\/ */
/*       calc_x_intersections(arg); */
/*       calc_y_intersections(arg); */
/*       if (compare_coord(arg, x)) */
/* 	project_vecx(arg, x); */
/*       else */
/* 	project_vecy(arg, x); */
/*     } */
/* } */
