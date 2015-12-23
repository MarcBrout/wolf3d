/*
** free_all.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec 22 19:56:24 2015 marc brout
** Last update Tue Dec 22 20:11:32 2015 marc brout
*/

#include "wolf.h"

void		free_all(t_param *arg)
{
  int		i;
  int		j;

  i = -1;
  while (++i < arg->nblvl)
    {
      j = -1;
      while (++j < arg->lvl[i].height)
	free(arg->lvl[i].map[j]);
      free(arg->lvl[i].map);
      free(arg->lvl[i].name);
      free(arg->lvl[i].desc);
      bunny_delete_clipable(&arg->lvl[i].mini->clipable);
    }
  free(arg->lvl);
}
