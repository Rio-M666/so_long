NAME = libftprintf.a
SRCS = ft_printf.c libft.c unit.c

OBJS=$(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
		ar rc $(NAME)  $(OBJS)
		ranlib $(NAME)
all:$(NAME)

%.o: %.c
		$(CC) -c $< -o $@
clean:
		rm -f $(OBJS)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re