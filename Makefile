##
## Makefile for wolf3d in /home/brout_m/rendu/projet/Infographie/gfx_wolf3d
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Dec 17 13:59:43 2015 marc brout
## Last update Sun Dec 20 00:28:17 2015 marc brout
##

SRCP	= ./src/

SRCP2	= ./tcore/

SRC     = $(SRCP)wolf.c \
	$(SRCP)check_file.c \
	$(SRCP)fill_tablvl.c \
	$(SRCP)aff_wolf.c \
	$(SRCP)calc.c \
	$(SRCP)intersections.c \
	$(SRCP)my_getnbr.c \
	$(SRCP)my_strdup.c \
	$(SRCP)my_strlen.c \
	$(SRCP)my_strcmp.c \
	$(SRCP2)tekpixel.c \
	$(SRCP2)vecnorm.c

OBJS    = $(SRC:.c=.o)

NAME    = wolf3d

CC      = gcc -g

CFLAGS  = -W -Wall -Werror -ansi -pedantic -I./include/

LDFLAGS = -L/usr/local/lib \
	-llapin \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ -ldl \
	-lm \
	-L./lib/ \

RM      = rm -f

.c.o:
	@$(CC) -c $< -o $@ $(CFLAGS)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
