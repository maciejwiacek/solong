# PROJECT NAME #
NAME =	so_long

# FILES #
SRC =	src/main.c \
			src/global_utils.c \
			src/parse_map.c \
			src/validate_map.c \
			src/validate_map2.c \
			src/validate_utils.c \
			src/flood_fill.c
OBJ =	$(SRC:.c=.o)

# COMMANDS #
CC =	gcc
RM =	rm -rf

# RULES #
all:	$(NAME)

$(NAME):	$(OBJ)
	make -C app
	$(CC) $(OBJ) app/libftprintf.a -o $(NAME)

clean:
	make clean -C app
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re