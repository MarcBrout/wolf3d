/*
** go.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 18 17:04:33 2015 marc brout
** Last update Tue Dec 22 01:25:48 2015 marc brout
*/

#include "wolf.h"

void		go(t_bunny_position *pos,
		   double angle,
		   t_bunny_position *newpos,
		   int move)
{
  newpos.x = pos.x + cos(angle) * move;
  newpos.y = pos.y + sin(angle) * move;
}
