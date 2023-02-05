#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

// todo: check if the return value of the write() is size_t or ssize_t...!!!
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
int ft_printf(const char *str, ...);
size_t ft_putnbr(int nbr);
size_t ft_convert_base(unsigned long long num, unsigned long long base, char format);
#endif