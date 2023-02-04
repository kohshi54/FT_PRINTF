#include "ft_printf.h"

size_t ft_convert_base(unsigned long num, unsigned long base)
{
	char	memo[] = "0123456789abcdef"; // MOVE THIS TO HEADER FILE LATER!!! ONLY ELIGIBLE TO BASE 16
	size_t	len;

	len = 0; // doing this in recursion, len is always set to 0?? CHECK THIS LATER. Write this outside??
	if (num >= base)
	{
		len += ft_convert_base(num / base, base);
		len += ft_putchar(memo[num % base]);
	}
	else
	{
		len += ft_putchar(memo[num]);
	}
	return (len);
}
