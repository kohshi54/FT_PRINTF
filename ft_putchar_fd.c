#include <unistd.h>

size_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, sizeof(c)));
}