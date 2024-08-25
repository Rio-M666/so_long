NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c putchar.c # 他のソースファイルを追加
OBJS = $(SRCS:.c=.o)
HEADERS = dict.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
