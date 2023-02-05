#include "ft_printf.h"

size_t ft_convert_base(unsigned long long num, unsigned long long base, char format)
{
	size_t	len;

	len = 0;
	if (num >= base)
	{
		len += ft_convert_base(num / base, base, format);
		len += ft_convert_base(num % base, base, format);
	}
	else
	{
		if (num < 10)
		{
			len += ft_putchar(num + '0');
		}
		else
		{
			if (format == 'p' || format == 'x')
				len += ft_putchar((num - 10) + 'a');
			else if (format == 'X')
				len += ft_putchar((num - 10) + 'A');
		}
	}
	return (len);
}
