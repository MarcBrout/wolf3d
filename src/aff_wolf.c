/*
** aff_wolf.c for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Dec 18 16:11:12 2015 marc brout
** Last update Sun Dec 20 16:24:11 2015 marc brout
*/

#include "wolf.h"

t_bunny_response	my_keys(t_bunny_event_state state,
				t_bunny_keysym keysym,
				void *data)
{
  t_param		*arg;

  arg = data;
  if (keysym == BKS_ESCAPE && state == GO_DOWN)
    {
      return (EXIT_ON_SUCCESS);
    }
  if (keysym == BKS_RIGHT && state == GO_DOWN)
    {
      arg->lvl[arg->curlvl].plangle += -1;
      if (arg->lvl[arg->curlvl].plangle <= 0)
	arg->lvl[arg->curlvl].plangle = 359;
      return (GO_ON);
    }
  if (keysym == BKS_LEFT && state == GO_DOWN)
    {
      arg->lvl[arg->curlvl].plangle += 1;
      if (arg->lvl[arg->curlvl].plangle >= 360)
	arg->lvl[arg->curlvl].plangle = 0;
      return (GO_ON);
    }
  if (keysym == BKS_UP && state == GO_DOWN)
    {
      arg->lvl[arg->curlvl].playerx += 1;
      return (GO_ON);
    }
  if (keysym == BKS_DOWN && state == GO_DOWN)
    {
      arg->lvl[arg->curlvl].playerx -= 1;
      return (GO_ON);
    }
  return (GO_ON);
}

t_bunny_response	main_wolf(void *data)
{
  t_param		*arg;

  arg = data;
  sky(arg);
  bottom(arg);
  calc_walls(arg);
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

char		aff_wolf(t_param *arg)
{
  arg->curlvl = 0;
  arg->key = &my_keys;
  if ((arg->pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL ||
      (arg->win = bunny_start(WIDTH, HEIGHT, 0, "WOLFY")) == NULL)
    return (1);
  bunny_set_loop_main_function(main_wolf);
  bunny_set_key_response(arg->key);
  bunny_loop(arg->win, 24, arg);
  bunny_delete_clipable(&arg->pix->clipable);
  bunny_stop(arg->win);
  return (0);
}
