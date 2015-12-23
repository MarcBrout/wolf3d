/*
** keyboard_mouse.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Tue Dec 22 19:34:41 2015 marc brout
** Last update Tue Dec 22 19:47:22 2015 marc brout
*/

#include "wolf.h"

void		double_tap(t_param *arg, const bool *keyboard)
{
  if (keyboard[BKS_Q] && keyboard[BKS_S])
    move_bw(arg, 45, 0.01);
  if (keyboard[BKS_D] && keyboard[BKS_S])
    move_bw(arg, -45, 0.01);
  if (keyboard[BKS_Q] && keyboard[BKS_Z])
    move_fw(arg, 45, 0.01);
  if (keyboard[BKS_D] && keyboard[BKS_Z])
    move_fw(arg, -45, 0.01);
}

void		simple_tap(t_param *arg, const bool *keyboard)
{
  if (keyboard[BKS_Z])
    move_fw(arg, 0, 0.1);
  if (keyboard[BKS_S])
    move_bw(arg, 0, 0.05);
  if (keyboard[BKS_Q])
    move_fw(arg, 90, 0.05);
  if (keyboard[BKS_D])
    move_bw(arg, 90, 0.05);
}

t_bunny_response		my_keys(t_bunny_event_state state,
					t_bunny_keysym keysym,
					void *data)
{
  const bool			*keyboard;
  t_param			*arg;

  arg = data;
  keyboard = bunny_get_keyboard();
  if (keysym == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  if (keyboard[BKS_LEFT])
    arg->curlvl = (arg->curlvl + 1 == arg->nblvl) ? 0 : arg->curlvl + 1;
  if (keyboard[BKS_RIGHT])
    arg->curlvl = (arg->curlvl - 1 >= 0) ? arg->curlvl - 1 : arg->nblvl - 1;
  double_tap(arg, keyboard);
  simple_tap(arg, keyboard);
  return (GO_ON);
}

void		move_fw(t_param *arg, double ang, double speed)
{
  double			x;
  double			y;

  ang = arg->lvl[arg->curlvl].plangle + ang;
  ang += (ang > 359) ? -359 : 0;
  x = arg->wm.costab[(int)ang] * speed;
  y = arg->wm.sintab[(int)ang] * speed;
  if ((int)(arg->lvl[arg->curlvl].playerx + x) > 0 &&
      (int)(arg->lvl[arg->curlvl].playerx + x) <
      (arg->lvl[arg->curlvl].width - 1)  &&
      !arg->lvl[arg->curlvl].map
      [(int)(arg->lvl[arg->curlvl].playery)]
      [(int)(arg->lvl[arg->curlvl].playerx + x)])
    arg->lvl[arg->curlvl].playerx += x;
  if ((int)(arg->lvl[arg->curlvl].playery + y) > 0 &&
      (int)(arg->lvl[arg->curlvl].playery + y) <
      (arg->lvl[arg->curlvl].height - 1) &&
      !arg->lvl[arg->curlvl].map
      [(int)(arg->lvl[arg->curlvl].playery + y)]
      [(int)(arg->lvl[arg->curlvl].playerx)])
    arg->lvl[arg->curlvl].playery += y;
}

void		move_bw(t_param *arg, double ang, double speed)
{
  double			x;
  double			y;

  ang = arg->lvl[arg->curlvl].plangle + ang;
  ang += (ang > 359) ? -359 : 0;
  x = arg->wm.costab[(int)ang] * speed;
  y = arg->wm.sintab[(int)ang] * speed;
  if ((int)(arg->lvl[arg->curlvl].playerx - x) > 0 &&
      (int)(arg->lvl[arg->curlvl].playerx - x) <
      (arg->lvl[arg->curlvl].width - 1)  &&
      !arg->lvl[arg->curlvl].map
      [(int)(arg->lvl[arg->curlvl].playery)]
      [(int)(arg->lvl[arg->curlvl].playerx - x)])
    arg->lvl[arg->curlvl].playerx -= x;
  if ((int)(arg->lvl[arg->curlvl].playery - y) > 0 &&
      (int)(arg->lvl[arg->curlvl].playery - y) <
      (arg->lvl[arg->curlvl].height - 1) &&
      !arg->lvl[arg->curlvl].map
      [(int)(arg->lvl[arg->curlvl].playery - y)]
      [(int)(arg->lvl[arg->curlvl].playerx)])
    arg->lvl[arg->curlvl].playery -= y;
}
