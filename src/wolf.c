/*
** wolf.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Dec 17 15:25:21 2015 marc brout
** Last update Tue Dec 22 20:22:59 2015 marc brout
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
}

char		launch_wolf(char **av)
{
  t_param	arg;

  if (open_ini(&arg, av) || check_all_lvl(&arg) || mal_tablvl(&arg))
    return (1);
  if (get_tabmap(&arg))
    return (1);
  arg.calc.p = 1;
  arg.calc.d = 0.5;
  set_cossin(&arg);
  if (aff_wolf(&arg))
    return (1);
  bunny_delete_ini(arg.ini);
  free_all(&arg);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  if (check_args(ac, env) || launch_wolf(av))
    return (1);
  return (0);
}
