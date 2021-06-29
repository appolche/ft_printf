#include "ft_printf.h"

static void	ft_print_hex(char *digit, t_flags flags)
{
	if (*digit == '0' && flags.dot == 0)
		write(1, " ", 1);
	else
		ft_putstr_fd(digit, 1);
}

static void	ft_int_dot(t_flags flags)
{
	int	dot;

	dot = flags.dot;
	while (dot-- != flags.len)
		write(1, "0", 1);
}

static void	ft_int_width(t_flags flags)
{
	int	width;

	width = flags.width;
	if (flags.dot >= flags.len && flags.dot <= width)
	{
		while (width-- != flags.dot)
			write(1, " ", 1);
	}
	else
	{
		if (flags.zero == 1 && flags.dot < 0)
		{
			while (width-- != flags.len)
				write(1, "0", 1);
		}
		else if (flags.dot < flags.len)
		{
			while (width-- != flags.len)
				write(1, " ", 1);
		}
	}
}

static int	ft_count(t_flags flags, int count)
{
	if (flags.width > flags.len && flags.width > flags.dot)
		count = flags.width;
	else if (flags.dot > flags.len && flags.dot > flags.width)
		count = flags.dot;
	else
		count = flags.len;
	return (count);
}

int	ft_hex(va_list ap, t_flags flags, int count)
{
	unsigned long long	d;
	char				*digit;

	d = (unsigned long long)va_arg(ap, unsigned int);
	if (d == 0 && flags.dot == 0 && flags.width == 0)
		return (count);
	digit = ft_itoa_hex(d, flags);
	flags.len = ft_strlen(digit);
	if (flags.width > flags.len && flags.minus == 0)
		ft_int_width(flags);
	if (flags.dot >= flags.len)
		ft_int_dot(flags);
	ft_print_hex(digit, flags);
	if (flags.width > flags.len && flags.minus == 1)
		ft_int_width(flags);
	count = ft_count(flags, count);
	if (digit)
		free(digit);
	return (count);
}
