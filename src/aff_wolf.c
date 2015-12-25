/*
** aff_wolf.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 18 16:11:12 2015 marc brout
** Last update Fri Dec 25 01:16:32 2015 marc brout
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
      arg->lvl[arg->curlvl].yangle += pos->y / 3;
      arg->lvl[arg->curlvl].plangle += pos->x / 3;
      if (arg->lvl[arg->curlvl].plangle <= 0)
	arg->lvl[arg->curlvl].plangle += 359;
      if (arg->lvl[arg->curlvl].plangle >= 359)
	arg->lvl[arg->curlvl].plangle -= 359;
    }
  else
    arg->mov = 0;
  if ((abs->x <= 200 || abs->x >= (WIDTH - 200)) ||
      (abs->y <= 200 || abs->y >= (HEIGHT - 200)))
    {
      bunny_set_mouse_position_window(arg->win, WIDTH / 2, HEIGHT / 2);
      arg->mov = 1;
    }
  return (GO_ON);
}

t_bunny_response	main_wolf(void *data)
{
  t_param		*arg;

  arg = data;
  simple_tap(arg);
  sky(arg);
  bottom(arg);
  calc_walls(arg);
  set_bump(arg, &arg->lvl[arg->curlvl]);
  add_player_to_mini(arg, &arg->lvl[arg->curlvl]);
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

  total = (WIDTH * HEIGHT) / 2 + (int)arg->lvl[arg->curlvl].yangle * WIDTH;
  pixels = arg->pix->pixels;
  i = -1;
  while (++i < total && total)
    pixels[i].full = SKY;
}

void		bottom(t_param *arg)
{
  int		i;
  t_color	*pixels;
  int		total;
  int		realt;

  realt = WIDTH * HEIGHT;
  total = (WIDTH * (HEIGHT + ABS(arg->lvl[arg->curlvl].yangle)));
  pixels = arg->pix->pixels;
  i = ZERO((WIDTH * HEIGHT) / 2 + (int)arg->lvl[arg->curlvl].yangle *
	   WIDTH);
  while (++i >= 0 && i < realt && i < total)
    pixels[i].full = FLOOR;
}

char		aff_wolf(t_param *arg)
{
  if ((arg->pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL ||
      (arg->win = bunny_start(WIDTH, HEIGHT, 0, "WOLFY")) == NULL)
    return (1);
  arg->curlvl = 0;
  arg->key = &my_keys;
  arg->move = &my_mouse;
  arg->mov = 1;
  set_minimaps(arg);
  bunny_set_loop_main_function(main_wolf);
  bunny_set_move_response(arg->move);
  bunny_set_key_response(arg->key);
  bunny_set_mouse_visibility(arg->win, 0);
  bunny_set_mouse_position_window(arg->win, WIDTH / 2, HEIGHT / 2);
  bunny_loop(arg->win, 24, arg);
  bunny_delete_clipable(&arg->pix->clipable);
  bunny_stop(arg->win);
  return (0);
}
