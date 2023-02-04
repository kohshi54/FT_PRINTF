#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

// todo: check if the return value of the write() is size_t or ssize_t...!!!
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
int ft_printf(const char *str, ...);
#endif