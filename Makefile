NAME = fractal

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = ./minilibx-linux
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L $(MLX_PATH) -lmlx -lXext -lX11 -lm

SRC = mlx_control.c utils.c julia.c build_set.c main.c mandelbrot.c error_handle.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(MLX_PATH)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

clean:
		make -C $(MLX_PATH) clean
		rm -rf *.o

fclean: clean
		rm -rf $(MLX_LIB)
		rm -rf $(NAME)
		rm -rf $(EXE)

re: fclean all

.PHONY: all clean fclean re