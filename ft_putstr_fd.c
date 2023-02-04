#include "ft_printf.h"

static int ft_strlen(char *s)
{
	size_t count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

size_t	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (-1); // check the return value when null comes!!!
	return (write(fd, s, ft_strlen(s)));
}
