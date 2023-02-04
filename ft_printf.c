#include "ft_printf.h"
#include <stdio.h>

// is it allowed to use STDOUT_FILENO macron for systme call??
// I am not sure because it coulb seen as global variable...

size_t	format_checker(va_list *ap, const char **format)
{
	// if there are no matching descriptor, return error??
	(*format)++;
	if (**format == 'c')
		return (ft_putchar_fd(va_arg(*ap, int), STDOUT_FILENO));
	if (**format == 's')
		return (ft_putstr_fd(va_arg(*ap, char *), STDOUT_FILENO));
	if (**format == 'p')
		return (1);
	// if (**format == 'd')
		// return (ft_putnbr_fd(va_arg(*ap, int), STDOUT_FILENO));
	// if (**format == 'x')
		// return (ft_putnbr_fd(va_arg(*ap, int), STDOUT_FILENO));
	// if (**format == 'x')
		// return (ft_putnbr_fd(va_arg(*ap, int), STDOUT_FILENO));
	return (1);
}

int ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			len += format_checker(&ap, &format); // check fomat descriptor %c, %s
		}
		else
		{
			len += ft_putchar_fd(*format, STDOUT_FILENO);
		}
		format++;
	}
	va_end(ap);
	return (len);
}

// int main(void)
// {
// 	size_t count;

// 	count = 0;
// 	count = ft_printf("abc%cdef%c%c%c", 'x', 'y', 'z', 'k');
// 	printf("\n%zu\n", count);

// 	count = printf("abc%cdef%c%c%c", 'x', 'y', 'z', 'k');
// 	printf("\n%zu", count);
// 	return (0);
// }
