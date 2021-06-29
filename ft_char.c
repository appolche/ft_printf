#include "ft_printf.h"

static int	ft_char_width(t_flags flags, char c, int count)
{
	int	width;

	width = flags.width;
	if (flags.minus == 0 && flags.zero == 0)
	{
		while (width-- != 1)
			write(1, " ", 1);
		write(1, &c, 1);
	}
	if (flags.zero == 1)
	{
		while (width-- != 1)
			write(1, "0", 1);
		write(1, &c, 1);
	}
	if (flags.minus == 1)
	{
		write(1, &c, 1);
		while (width-- != 1)
			write(1, " ", 1);
	}
	count = flags.width;
	return (count);
}

int	ft_char(va_list ap, t_flags flags, int count)
{
	char	c;

	if (flags.type == '%')
		c = '%';
	else
		c = (char)va_arg(ap, int);
	if (flags.width <= 1)
		count = write(1, &c, 1);
	else
		count = ft_char_width(flags, c, count);
	return (count);
}
