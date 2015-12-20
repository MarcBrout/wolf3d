/*
** tekpixel.c for fdf1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Nov 17 16:24:48 2015 marc brout
** Last update Thu Dec 17 10:56:49 2015 marc brout
*/

#include "lapin.h"

void		tekpixel(t_bunny_pixelarray	*pix,
			 t_bunny_position	*pos,
			 t_color		*color)
{
  t_color	*col;

  if ((pos->x >= 0) && (pos->x <= pix->clipable.clip_width) &&
      (pos->y >= 0) && (pos->y <= pix->clipable.clip_height))
    {
      col = (t_color*)pix->pixels + (pos->x +
				   (pos->y * pix->clipable.clip_width));
      col->argb[0] = color->argb[0];
      col->argb[1] = color->argb[1];
      col->argb[2] = color->argb[2];
      col->argb[3] = color->argb[3];
    }
}
