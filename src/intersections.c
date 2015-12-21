/*
** intersections.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Sat Dec 19 15:25:46 2015 marc brout
** Last update Mon Dec 21 10:39:01 2015 marc brout
*/

#include "wolf.h"

/* char		check_cell(t_param *arg, double x, double y) */
/* { */
/*   /\* printf("x=%f\n", x); *\/ */
/*   /\* printf("y=%f\n", y); *\/ */
/*   if (arg->lvl[arg->curlvl].map[(int)(y / arg->lvl[arg->curlvl].tiles)] */
/*       [(int)(x / arg->lvl[arg->curlvl].tiles)]) */
/*     { */
/*       /\* printf("FOUND\n"); *\/ */
/*       return (1); */
/*     } */
/*   return (0); */
/* } */

/* void		first_x_intersection(t_param *arg) */
/* { */
/*   /\* printf("calc.up = %d\n", arg->calc.up); *\/ */
/*   /\* printf("calc.yf = %f\n", arg->calc.yf); *\/ */
/*   arg->calc.x_y = (arg->calc.up) ? */
/*     ((int)(arg->calc.yf / arg->lvl[arg->curlvl].tiles)) * */
/*     arg->lvl[arg->curlvl].tiles - 1 : */
/*     ((int)(arg->calc.yf / arg->lvl[arg->curlvl].tiles)) * */
/*     arg->lvl[arg->curlvl].tiles + arg->lvl[arg->curlvl].tiles; */
/*   arg->calc.x_x = arg->calc.xf + */
/*     (arg->calc.yf - arg->calc.x_y) /  */
/*     arg->wm.tantab[(int)arg->calc.ang]; */
/*   /\* printf("%f\n", arg->wm.tantab[(int)arg->calc.ang]); *\/ */
/* } */

/* void		first_y_intersection(t_param *arg) */
/* { */
/*   /\* printf("calc.left = %d\n", arg->calc.left); *\/ */
/*   /\* printf("calc.yf = %f\n", arg->calc.yf); *\/ */
/*   /\* printf("calc.xf = %f\n", arg->calc.xf); *\/ */
/*   arg->calc.y_x = (arg->calc.left) ? */
/*     ((int)(arg->calc.xf / arg->lvl[arg->curlvl].tiles)) * */
/*     arg->lvl[arg->curlvl].tiles - 1 : */
/*     ((int)(arg->calc.xf / arg->lvl[arg->curlvl].tiles)) * */
/*     arg->lvl[arg->curlvl].tiles + arg->lvl[arg->curlvl].tiles; */
/*   /\* printf("calc.y_x = %f\n", arg->calc.y_x); *\/ */
/*   arg->calc.y_y = arg->calc.yf + */
/*     (arg->calc.xf - arg->calc.y_x) * */
/*     arg->wm.tantab[(int)arg->calc.ang]; */
/*   /\* printf("%f\n", arg->wm.tantab[(int)arg->calc.ang]); *\/ */
/* } */

/* void		calc_y_intersections(t_param *arg) */
/* { */
/*   /\* printf("\ny::\n"); *\/ */
/*   /\* printf("angle : %f\n", arg->calc.ang); *\/ */
/*   if ((int)arg->wm.tantab[(int)arg->calc.ang]) */
/*     { */
/*       first_y_intersection(arg); */
/*       if (check_cell(arg, arg->calc.y_x, arg->calc.y_y)) */
/* 	return ; */
/*       arg->calc.y_xa = (arg->calc.left) ? -arg->lvl[arg->curlvl].tiles : */
/* 	arg->lvl[arg->curlvl].tiles; */
/*       arg->calc.y_ya = arg->lvl[arg->curlvl].tiles * */
/* 	arg->wm.tantab[(int)arg->calc.ang]; */
/*       /\* printf("--------------\n"); *\/ */
/*       /\* printf("ya = %f\n", arg->calc.y_ya); *\/ */
/*       while (!check_cell(arg, arg->calc.y_x, arg->calc.y_y)) */
/* 	{ */
/* 	  arg->calc.y_x = (int)arg->calc.y_x + arg->calc.y_xa; */
/* 	  arg->calc.y_y = (int)arg->calc.y_y +  arg->calc.y_ya; */
/* 	} */
/*     } */
/* } */

/* void		calc_x_intersections(t_param *arg) */
/* { */
/*   /\* printf("\nx::\n"); *\/ */
/*   /\* printf("angle : %f\n", arg->calc.ang); *\/ */
/*   if ((int)arg->wm.tantab[(int)arg->calc.ang])  */
/*     { */
/*       first_x_intersection(arg); */
/*       if (check_cell(arg, arg->calc.x_x, arg->calc.x_y)) */
/* 	return ;   */
/*       arg->calc.x_ya = (arg->calc.up) ? -arg->lvl[arg->curlvl].tiles : */
/* 	arg->lvl[arg->curlvl].tiles; */
/*       arg->calc.x_xa = arg->lvl[arg->curlvl].tiles / */
/* 	arg->wm.tantab[(int)arg->calc.ang]; */
/*       /\* printf("--------------\n"); *\/ */
/*       /\* printf("xa = %f\n", arg->calc.x_xa); *\/ */
/*       while (!check_cell(arg, arg->calc.x_x, arg->calc.x_y)) */
/* 	{ */
/* 	  arg->calc.x_x = (int)arg->calc.x_x + arg->calc.x_xa; */
/* 	  arg->calc.x_y = (int)arg->calc.x_y + arg->calc.x_ya; */
/* 	} */
/*     } */
/* } */
