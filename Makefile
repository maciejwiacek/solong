# PROJECT NAME #
NAME =	so_long

# FILES #
SRC =	src/main.c \
			src/global_utils.c \
			src/parse_map.c \
			src/validate_map.c \
			src/validate_map2.c \
			src/validate_utils.c \
			src/flood_fill.c \
			src/start_game.c \
			src/input_handling.c \
			src/movement_handling.c \
			src/struct_init.c \
			src/render_utils.c
MLX =	minilibx-linux
OBJ =	$(SRC:.c=.o)

# COMMANDS #
CC =	cc
RM =	rm -rf

<<<<<<< HEAD
<<<<<<< HEAD
OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all: clone $(NAME)
=======
# RULES #
all:	clone $(NAME)
>>>>>>> parent of a31a57b (TODO: memleaks + validation)

clone:
	if [ ! -d "minilibx-linux" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git; \
	fi

<<<<<<< HEAD
$(NAME): $(OBJS)
=======
# RULES #
all:	$(NAME)

$(NAME):	$(OBJ)
	git clone https://github.com/42Paris/minilibx-linux.git
>>>>>>> parent of 96281b7 (TODO: Check everything and push)
=======
$(NAME):	$(OBJ)
>>>>>>> parent of a31a57b (TODO: memleaks + validation)
	make -C app
	make -C minilibx-linux
	$(CC) $(OBJ) app/libftprintf.a -L$(MLX) -lmlx_Linux -lX11 -lXext -lm -o $(NAME)

clean:
	make clean -C app
	make clean -C minilibx-linux
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
