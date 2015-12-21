/*
** wolf3d.h for wolf
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Dec 17 15:13:48 2015 marc brout
** Last update Mon Dec 21 12:19:51 2015 marc brout
*/

#ifndef WOLF_H_
# define WOLF_H_
# define WIDTH 1280
# define HEIGHT 1024
# define FLOOR BLACK
# define WALL WHITE
# define SKY RED
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
  double		ang;
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
}			t_param;

t_bunny_response my_keys(t_bunny_event_state, t_bunny_keysym, void *);
t_bunny_response main_wolf(void *);
double vecnorm(t_bunny_position *, t_bunny_position *);
void set_cossin(t_param *);
void sky(t_param *);
void bottom(t_param *);
void basic_to_sec(t_param *, int);
void check_angle(t_param *);
void calc_walls(t_param *);
void first_x_intersection(t_param *);
void first_y_intersection(t_param *);
void calc_x_intersections(t_param *);
void calc_y_intersections(t_param *);
char compare_coord(t_param *, int);
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

#endif 
