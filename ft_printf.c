#include "ft_printf.h"

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
		return (ft_putstr("0x") + ft_convert_base(va_arg(*ap, unsigned long long), 16, **format));
	if (**format == 'd')
		return (ft_putnbr(va_arg(*ap, unsigned long long)));
	if (**format == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	if (**format == 'u')
		return (ft_convert_base(va_arg(*ap, unsigned int), 10, **format));
	if (**format == 'x')
		return (ft_convert_base(va_arg(*ap, unsigned int), 16, **format));
	if (**format == 'X')
		return (ft_convert_base(va_arg(*ap, unsigned int), 16, **format));
	if (**format == '%')
		return (ft_putchar('%'));
	return (-1); // what is return here?
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
			len += format_checker(&ap, &format);
		}
		else
		{
			len += ft_putchar(*format);
		}
		format++; // why move foramt instead of ap??
	}
	va_end(ap);
	return (len);
}
