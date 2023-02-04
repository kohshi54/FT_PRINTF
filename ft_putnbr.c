#include "ft_printf.h"
#include <limits.h>

size_t	ft_putnbr(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putchar(nbr % 10 + '0');
	}
	else
	{
		len += ft_putchar(nbr + '0');
	}
	return (len);
}
