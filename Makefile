NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_convert_base.c ft_putnbr.c
OBJS = $(SRCS:%.c=%.o)
INCLUDES = ft_printf.h

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

clean :
	rm -f $(OBJS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

.PHONY : clean fclean re all