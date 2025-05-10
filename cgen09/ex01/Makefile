NAME =libft.a
SRCS=ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS=$(SRCS:.c=.o)
CCCFLAG=-Wall -Wextra -Werror

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(LIBDIR) $(LIBS)

$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) $(INCDIR) -c $(SRCS)

all: clean $(OBJS) $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET) *.d
fclean:clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re