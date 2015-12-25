/*
** wolf.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Dec 17 15:25:21 2015 marc brout
** Last update Fri Dec 25 01:47:21 2015 marc brout
*/

#include "wolf.h"

void		whats_up(char **av, int err)
{
  if (err == 1)
    {
      write(2, av[1], my_strlen(av[1]));
      write(2, " file corrupted, execution aborted.\n", 37);
    }
  if (err == 2)
    write(2, "Trouble loading map, executon aborted.\n", 40);
}

void		set_cossin(t_param *arg)
{
  int		i;

  i = -1;
  while (++i < WIDTH)
    {
      arg->wm.ydep[i] = (arg->calc.p * (WIDTH / 2 - i)) / WIDTH;
      if (i < 360)
	{
	  arg->wm.costab[i] = cos((double)RAD(i));
	  arg->wm.sintab[i] = sin((double)RAD(i));
	}
    }
}

char		launch_wolf(char **av)
{
  t_param	arg;

  arg.calc.p = 1;
  arg.calc.d = 0.5;
  arg.calc.mini = HEIGHT / 50;
  if (open_ini(&arg, av) || check_all_lvl(&arg) || mal_tablvl(&arg))
    return (1);
  if (get_tabmap(&arg))
    return (2);
  set_cossin(&arg);
  if (aff_wolf(&arg))
    return (2);
  bunny_delete_ini(arg.ini);
  free_all(&arg);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  int		err;

  if (check_args(ac, env))
    return (1);
  if ((err = launch_wolf(av)))
    {
      whats_up(av, err);
      return (1);
    }
  return (0);
}
