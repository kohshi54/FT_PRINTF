NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_putchar_fd.c ft_putstr_fd.c
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