##
## EPITECH PROJECT, 2022
## makefile
## File description:
## my_hunter
##

SRC		=	set_values.c	\
			set_game.c		\
			set_game_info.c	\
			open_pattern.c	\
			create_grid.c	\
			gol.c 			\
			game.c 			\
			bad_apple/bad_apple.c 		\
			bad_apple/frame_manager.c	\
			bad_apple/my_int_to_str.c 	\

OBJ 	= 	$(SRC:.c=.o)

NAME	=	my_gol

CFLAGS 	= 	-W -Wall -Wextra -I./include

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f *~
	rm $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean	all

all:	$(NAME)

.PHONY:	debug
		clean
		fclean
		re
		all
