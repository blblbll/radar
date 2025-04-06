##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefle
##

SRC	=	main.c\
		error.c\
		display.c\
		collision.c\
		deplacement.c\
		lib/openf.c\
		lib/my_str_to_word_array.c\
		lib/lib2.c\
		lib/my_get_nbr.c\
		data/avion.c\
		data/tower.c\
		data/info.c\

NAME	=	my_radar

INCLUDE	=	-I include/

CFLAGS 	=	-W -Wall -Wextra

VFLAGS	=	--leak-check=full

all:	$(NAME)

$(NAME):
	gcc -g -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system -lm
	make clean

clean:
	find . -type f -name "*#" -a -name "#*" -delete -o -name "*~" -delete

fclean: clean
	rm -rf $(NAME)

re: fclean all
