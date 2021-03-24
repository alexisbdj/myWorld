DSRC	=	src

SRC	=	$(DSRC)/main.c	\
		$(DSRC)/game.c	\
		$(DSRC)/game_run.c	\
		$(DSRC)/matrix.c	\
		$(DSRC)/world.c	\
		$(DSRC)/world_update.c	\
		$(DSRC)/my_maths.c	\
		$(DSRC)/world_prerender.c	\
		$(DSRC)/button.c	\
		$(DSRC)/button_create.c	\
		$(DSRC)/tool_pannel.c	\
		$(DSRC)/v_fill.c	\
		$(DSRC)/ground_map_update.c	\
		$(DSRC)/prepare_3d_map.c	\
		$(DSRC)/projection_2d.c	\
		$(DSRC)/keyboard.c	\
		$(DSRC)/mouse_update.c	\
		$(DSRC)/ground_update.c	\
		$(DSRC)/world_misc.c	\
		$(DSRC)/world_create_parts.c	\
		$(DSRC)/update_point.c	\
		$(DSRC)/args.c	\
		$(DSRC)/save.c	\
		$(DSRC)/mini_lib.c	\
		$(DSRC)/find_point_on_proj.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_world

INCLUDE	=	-Iinclude

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lm

CFLAGS	=	-Iinclude

CC	=	gcc

RM	=	rm

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(INCLUDE) $(LDFLAGS)

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
