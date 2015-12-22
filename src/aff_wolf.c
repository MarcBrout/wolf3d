/*
** aff_wolf.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 18 16:11:12 2015 marc brout
** Last update Tue Dec 22 18:20:05 2015 marc brout
*/

#include "wolf.h"

t_bunny_response		my_mouse(const t_bunny_position *pos,
					 void *data)
{
  const t_bunny_position	*abs;
  t_param			*arg;

  arg = data;
  abs = bunny_get_mouse_position();
  if (!arg->mov)
    {
      arg->lvl[arg->curlvl].plangle += pos->x / 5;
      if (arg->lvl[arg->curlvl].plangle <= 0)
	arg->lvl[arg->curlvl].plangle += 359;
      if (arg->lvl[arg->curlvl].plangle >= 359)
	arg->lvl[arg->curlvl].plangle -= 359;
    }
  else
    arg->mov = 0;
  if (abs->x <= 100 || (abs->x >= WIDTH - 100))
    {
      bunny_set_mouse_position(WIDTH / 2, HEIGHT / 2);
      arg->mov = 1;
    }
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
  if (!arg->lvl[arg->curlvl].map
      [(int)(arg->lvl[arg->curlvl].playery)]
      [(int)(arg->lvl[arg->curlvl].playerx + x)])
    arg->lvl[arg->curlvl].playerx += x;
  if (!arg->lvl[arg->curlvl].map
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
  if (!arg->lvl[arg->curlvl].map
      [(int)(arg->lvl[arg->curlvl].playery)]
      [(int)(arg->lvl[arg->curlvl].playerx - x)])
    arg->lvl[arg->curlvl].playerx -= x;
  if (!arg->lvl[arg->curlvl].map
      [(int)(arg->lvl[arg->curlvl].playery - y)]
      [(int)(arg->lvl[arg->curlvl].playerx)])
    arg->lvl[arg->curlvl].playery -= y;
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
  if (keyboard[BKS_Q] && keyboard[BKS_S])
    move_bw(arg, 45, 0.02);
  if (keyboard[BKS_D] && keyboard[BKS_S])
    move_bw(arg, -45, 0.02);
  if (keyboard[BKS_Q] && keyboard[BKS_Z])
    move_fw(arg, 45, 0.02);
  if (keyboard[BKS_D] && keyboard[BKS_Z])
    move_fw(arg, -45, 0.02);
  if (keyboard[BKS_Z])
    move_fw(arg, 0, 0.05);
  if (keyboard[BKS_S])
    move_bw(arg, 0, 0.05);
  if (keyboard[BKS_Q])
    move_fw(arg, 90, 0.05);
  if (keyboard[BKS_D])
    move_bw(arg, 90, 0.05);
  return (GO_ON);
}

t_bunny_response	main_wolf(void *data)
{
  t_param		*arg;

  arg = data;
  sky(arg);
  bottom(arg);
  calc_walls(arg);
  set_bump(&arg->lvl[arg->curlvl]);
  add_player_to_mini(&arg->lvl[arg->curlvl]);
  put_border(arg, 6, BORDER);
  put_border(arg, 4, BORDERIN);
  put_border(arg, 2, BORDEROU);
  mini_map(arg, &arg->lvl[arg->curlvl]);
  bunny_blit(&arg->win->buffer, &arg->pix->clipable, NULL);
  bunny_display(arg->win);
  return (GO_ON);
}

void		sky(t_param *arg)
{
  int		i;
  t_color	*pixels;
  int		total;

  total = (WIDTH * HEIGHT) / 2;
  pixels = arg->pix->pixels;
  i = -1;
  while (++i < total)
    pixels[i].full = SKY;
}

void		bottom(t_param *arg)
{
  int		i;
  t_color	*pixels;
  int		total;

  total = (WIDTH * HEIGHT);
  pixels = arg->pix->pixels;
  i = (WIDTH * HEIGHT) / 2 - 1;
  while (++i < total)
    pixels[i].full = FLOOR;
}

char				aff_wolf(t_param *arg)
{
  const t_bunny_position	*pos;

  if ((arg->pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL ||
      (arg->win = bunny_start(WIDTH, HEIGHT, 0, "WOLFY")) == NULL)
    return (1);
  arg->curlvl = 0;
  arg->key = &my_keys;
  arg->move = &my_mouse;
  arg->mov = 0;
  set_minimaps(arg);
  bunny_set_loop_main_function(main_wolf);
  bunny_set_move_response(arg->move);
  bunny_set_key_response(arg->key);
  bunny_set_mouse_visibility(arg->win, 0);
  bunny_set_mouse_position_window(arg->win, WIDTH / 2, HEIGHT / 2);
  pos = bunny_get_mouse_position();
  arg->margl = pos->x - WIDTH / 2 + 200; 
  arg->margr = pos->x + WIDTH / 2 - 200; 
  bunny_loop(arg->win, 24, arg);
  bunny_set_mouse_visibility(arg->win, 1);
  bunny_delete_clipable(&arg->pix->clipable);
  bunny_stop(arg->win);
  return (0);
}
