/*
** fill_tablvl.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 18 11:50:49 2015 marc brout
** Last update Fri Dec 25 02:01:46 2015 marc brout
*/

#include "wolf.h"

void		get_player(t_param *arg, t_lvl *lvl)
{
  lvl->tiles = my_getnbr(FLD(arg->ini, lvl->name, "tile_size", 0));
  lvl->playerx = my_getnbr(FLD(arg->ini, lvl->name, "start_position", 0));
  lvl->playery = my_getnbr(FLD(arg->ini, lvl->name, "start_position", 1));
  lvl->plangle = (my_getnbr(FLD(arg->ini, lvl->name, "start_position", 2))
		  % 360);
  if (!lvl->playerx || !lvl->playery || lvl->playerx >= lvl->width || 
      lvl->playery >= lvl->height)
    {
      lvl->playerx = 0;
      lvl->playery = 0;
      while (lvl->map[(int)lvl->playery][(int)lvl->playerx])
	{
	  lvl->playerx += 1;
	  if (lvl->playerx == lvl->width)
	    {
	      lvl->playerx = 0;
	      lvl->playery += 1;
	    }
	}
    }
  lvl->yangle = 0;
  lvl->playerx += 0.5;
  lvl->playery += 0.5;
}

char		get_lvl_map(t_param *arg, t_lvl *lvl)
{
  int		x;
  int		y;
  int		ind;
  const char	*nb;
  char		pres;

  y = -1;
  pres = 0;
  while (++y < lvl->height)
    {
      x = -1;
      while (++x < lvl->width)
	{
	  ind = x + (lvl->height - 1 - y) * lvl->width;
	  if ((nb = FLD(arg->ini, lvl->name, "data", ind)) == NULL)
	    return (1);
	  lvl->map[y][x] = my_getnbr(nb);
	  if (!lvl->map[y][x])
	    pres = 1;
	}
    }
  if (!pres)
    return (1);
  return (0);
}

char		get_tabmap(t_param *arg)
{
  int		i;

  i = -1;
  while (++i < arg->nblvl)
    {
      if (get_lvl_map(arg, &arg->lvl[i]))
	return (1);
      get_player(arg, &arg->lvl[i]);
    }
  return (0);
}

char		mal_lvl_map(t_param *arg, t_lvl *lvl)
{
  int		i;

  if ((lvl->height = my_getnbr(FLD(arg->ini, lvl->name, "height", 0))) < 3
      || (lvl->width = my_getnbr(FLD(arg->ini, lvl->name, "width", 0))) < 3)
    return (1);
  if (mal_mini_map(arg, lvl))
    return (2);
  if ((lvl->map = bunny_malloc(sizeof(int *) * (lvl->height + 1))) == NULL)
    return (3);
  i = -1;
  while (++i < lvl->height)
    if ((lvl->map[i] = bunny_malloc(sizeof(int) *
				    (lvl->width + 1))) == NULL)
      return (4);
  return (0);
}

char		mal_tablvl(t_param *arg)
{
  char		*name;
  int		i;

  if ((arg->lvl = bunny_malloc(sizeof(t_lvl) * (arg->nblvl + 1))) == NULL)
    return (1);
  i = -1;
  while (++i < arg->nblvl &&
	 (name = (char *)FLD(arg->ini, NULL, "lvlscope", i)) != NULL)
    {
      if ((arg->lvl[i].name = my_strdup(name)) == NULL)
	return (2);
      if ((arg->lvl[i].desc =
	   my_strdup((char *)FLD(arg->ini, name, "name", 0))) == NULL)
	return (3);
      if (mal_lvl_map(arg, &arg->lvl[i]))
	return (4);
    }
  return (0);
}
