
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42 -I.

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz
MLX_INCLUDES = -I$(MLX_PATH)

SRCS = src/main.c  src/check.c src/check2.c src/game.c src/image.c src/map.c src/key.c

ALL_SRCS=$(SRCS) $(LIBFT)
OBJS = $(SRCS:.c=.o)

all: mlx_make $(NAME)

mlx_make:
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean


fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean


re: fclean all

test: $(NAME)
	./$(NAME) test.ber

.PHONY: all clean fclean re test mlx_make