#include "ft_printf.h"

static int	ft_counter(t_flags flags, int count)
{
	int	width;

	width = flags.width;
	if (flags.width < 0)
		width = flags.width * (-1);
	if (width > flags.len)
		count = width;
	else
		count = flags.len;
	return (count);
}

static int	ft_if_ptr(char *digit, t_flags flags, int count)
{
	int	width;

	width = flags.width;
	if (flags.width < 0)
		width = flags.width * (-1);
	if (width > flags.len && flags.minus == 0)
	{
		while (width-- != flags.len)
			write(1, " ", 1);
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(digit, 1);
	if (width > flags.len && flags.minus == 1)
	{
		while (width-- != flags.len)
			write(1, " ", 1);
	}
	count = ft_counter(flags, count);
	return (count);
}

int	ft_pointr(va_list ap, t_flags flags, int count)
{
	unsigned long long	d;
	char				*digit;

	d = va_arg(ap, unsigned long long);
	digit = ft_itoa_hex(d, flags);
	flags.len = ft_strlen(digit) + 2;
	count = ft_if_ptr(digit, flags, count);
	if (digit)
		free(digit);
	return (count);
}
