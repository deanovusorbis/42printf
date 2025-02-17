NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putptr.c \
	ft_putstr.c \
	ft_putunbr.c \
	ft_putx.c \
	ft_extra.c

OBJS= $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

