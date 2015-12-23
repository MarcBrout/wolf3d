/*
** wolf3d.h for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Dec 17 15:13:48 2015 marc brout
** Last update Tue Dec 22 20:19:15 2015 marc brout
*/

#ifndef WOLF_H_
# define WOLF_H_
# define WIDTH 1024
# define HEIGHT 768
# define MINI (HEIGHT / 50)
# define FLOOR 0xFF2222B2
# define PLAYER 0xFF00D7FF
# define WALL 0xFFADDEFF
# define WALLGREY 0xFF8CB4DE
# define SKY 0xFFDCF8FF
# define BORDER 0xFF0045FF
# define BORDERIN 0xFF00A5FF
# define BORDEROU 0xFF00D7FF
# define FLD bunny_ini_get_field
# define ABS(val) (((val) < 0) ? -(val) : (val))
# define GET_X(val) ABS((WIDTH / 2) - WIDTH + (val))
# define DEGRE(val) (((val) / M_PI) * 180)
# define RAD(val) (((val) * M_PI) / 180)

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include "lapin.h"

typedef struct		s_lvl
{
  char			*name;
  char			*desc;
  int			tiles;
  int			width;
  int			height;
  int			**map;
  t_bunny_pixelarray	*mini;
  int			minipos;
  double		playerx;
  double		playery;
  double		plangle;
}			t_lvl;

typedef struct		s_wmath
{
  double		costab[360];
  double		sintab[360];
}			t_wmath;

typedef struct		s_calc
{
  double		d;
  double		p;
  double		k;
  double		vecx;
  double		vecy;
  double		xf;
  double		yf;
}			t_calc;

typedef struct		s_param
{
  t_calc		calc;
  t_wmath		wm;
  int			curlvl;
  int			nblvl;
  t_lvl			*lvl;
  t_bunny_ini		*ini;
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_bunny_key		key;
  t_bunny_move		move;
  char			mov;
}			t_param;

t_bunny_response my_mouse(const t_bunny_position *, void *);
t_bunny_response my_keys(t_bunny_event_state, t_bunny_keysym, void *);
t_bunny_response main_wolf(void *);
double vecnorm(t_bunny_position *, t_bunny_position *);
void free_all(t_param *);
void double_tap(t_param *, const bool *);
void simple_tap(t_param *, const bool *);
void move_fw(t_param *, double, double);
void move_bw(t_param *, double, double);
void mini_map(t_param *, t_lvl *);
void set_cossin(t_param *);
void sky(t_param *);
void bottom(t_param *);
void basic_to_sec(t_param *, int);
void check_angle(t_param *);
void calc_walls(t_param *);
void set_lvl_minimap(t_lvl *);
void set_minimaps(t_param *);
void set_bump(t_lvl *);
void put_border(t_param *, int, unsigned int);
void add_player_to_mini(t_lvl *);
void tek_circle(t_lvl *, int);
void add_player_to_mini(t_lvl *);
char mal_mini_map(t_lvl *);
char aff_wolf(t_param *);
int my_strcmp(const char *, char *);
int my_strlen(const char *);
int my_getnbr(const char *);
char *my_strdup(char *);
char get_lvl_map(t_param *, t_lvl *);
char get_tabmap(t_param *);
char mal_lvl_map(t_param *, t_lvl *);
char mal_tablvl(t_param *);
char launch_wolf(char **);
char open_ini(t_param *, char **);
char check_lvl(t_param *, char *);
char check_all_lvl(t_param *);
char check_args(int, char **);

#endif /* !WOLF_H_ */
