##
## EPITECH PROJECT, 2019
## Makefille
## File description:
## Makefille minishell 2
##

NAME		=	mysh

SRC		=	src/main.c		\
			src/start_msh.c		\
			src/my_system_call.c	\
			src/my_get_next_line.c	\
			src/my_command.c	\
			src/my_str_to_wordtab.c	\
			src/parse_env.c		\
			src/epu_str.c		\
			src/modif_tab.c		\
			src/my_memcpy.c

OBJ		=	$(SRC:.c=.o)

CPPFLAGS	=	-I ./include

CFLAGS		=	-W -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
