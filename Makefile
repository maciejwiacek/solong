# PROJECT NAME #
NAME =	so_long

# FILES #
SRC =	src/main.c \
			src/ft_lstnew.c \
			src/ft_lstadd_back.c \
			src/global_utils.c \
			src/parse_map.c \
			src/validate_map.c \
			src/validate_map2.c
OBJ =	$(SRC:.c=.o)

# COMMANDS #
CC =	gcc
RM =	rm -rf

# RULES #
all:	$(NAME)

$(NAME):	$(OBJ)
	make -C app
	$(CC) $(OBJ) app/libftprintf.a -o main

clean:
	make clean -C app
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re