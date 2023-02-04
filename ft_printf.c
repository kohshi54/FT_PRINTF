#include "ft_printf.h"
#include <stdio.h>

// is it allowed to use STDOUT_FILENO macron for systme call??
// I am not sure because it coulb seen as global variable...

size_t	format_checker(va_list *ap, const char **format)
{
	// if there are no matching descriptor, return error??
	(*format)++;
	if (**format == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (**format == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (**format == 'p')
		return (ft_putstr("0x") + ft_convert_base(va_arg(*ap, unsigned long), 16));
	if (**format == 'd')
		return (ft_putnbr(va_arg(*ap, int)));
	if (**format == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	if (**format == 'u')
		return (ft_putnbr(va_arg(*ap, int))); // need to adjast to positive numbers above
	if (**format == 'x')
		return (ft_convert_base(va_arg(*ap, unsigned long), 16));
	if (**format == 'X')
		return (ft_convert_base(va_arg(*ap, unsigned long), 16)); // need to adjast to upper casea
	if (**format == '%')
		return (ft_putchar('%'));
	return (1); // what is return here?
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
		
			len += format_checker(&ap, &format); // check fomat descriptor
		}
		else
		{
			len += ft_putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (len);
}

// int main(void)
// {
// 	// size_t count;

// 	// count = 0;
// 	// count = ft_printf("abc%cdef%c%c%c", 'x', 'y', 'z', 'k');
// 	// printf("\n%zu\n", count);

// 	// count = printf("abc%cdef%c%c%c", 'x', 'y', 'z', 'k');
// 	// printf("\n%zu", count);

// 	// char c = 'c';
// 	// ft_printf("%p\n", &c);
// 	// printf("%p\n", &c);

// 	// ft_printf("%d\n", 225);
// 	return (0);
// }
