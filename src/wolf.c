/*
** wolf.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Dec 17 15:25:21 2015 marc brout
** Last update Mon Dec 21 12:17:09 2015 marc brout
*/

#include "wolf.h"

void		set_cossin(t_param *arg)
{
  int		i;

  i = -1;
  while (++i < 360)
    {
      arg->wm.costab[i] = cos((double)RAD(i));
      arg->wm.sintab[i] = sin((double)RAD(i));
    }
  i = -1;
  while (++i < 360)
    {
      printf("cos [%d°] = %f ||", i, arg->wm.costab[i]);       
      printf("sin [%d°] = %f\n", i, arg->wm.sintab[i]); 
    }
}

char		launch_wolf(char **av)
{
  t_param	arg;
  int		x;
  int		y;
  int		i;

  if (open_ini(&arg, av) || check_all_lvl(&arg) || mal_tablvl(&arg))
    return (1);
  if (get_tabmap(&arg))
    return (1);
  arg.calc.p = 1;
  arg.calc.d = 0.7;
  set_cossin(&arg);
  if (aff_wolf(&arg))
    return (1);
  i = -1;
  while (++i < arg.nblvl)
    {
      y = -1;
      printf("======================\n");
      printf("%s\n", arg.lvl[i].name);
      printf("%s\n", arg.lvl[i].desc);
      printf("======================\n");
      printf("playerx=%f\n", arg.lvl[i].playerx);
      printf("playery=%f\n", arg.lvl[i].playery);
      printf("plangle=%f\n", arg.lvl[i].plangle);
      while (++y < arg.lvl[i].height)
	{
	  x = -1;
	  while (++x < arg.lvl[i].width)
	    printf("%d", arg.lvl[i].map[y][x]);
	  printf("\n");
	}
      printf("\n");
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  if (check_args(ac, env))
    return (1);
  launch_wolf(av);
  return (0);
}
