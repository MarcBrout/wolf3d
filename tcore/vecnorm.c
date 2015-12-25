/*
** vecnorm.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 18 16:59:45 2015 marc brout
** Last update Thu Dec 24 15:01:29 2015 marc brout
*/

#include "wolf.h"

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  return (sqrt(pow((double)(coord1->x - coord0->x), 2) +
	       pow((double)(coord1->y - coord0->y), 2)));
}
