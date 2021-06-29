#include "ft_printf.h"

static void	ft_print_int(char *digit, t_flags flags)
{
	if (*digit == '-' && ((flags.dot >= flags.len) || (flags.zero == 1
				&& flags.dot < 0 && flags.width > flags.len)))
	{
		digit++;
		ft_putstr_fd(digit, 1);
	}
	else if (*digit == '0' && flags.dot == 0)
		write(1, " ", 1);
	else
		ft_putstr_fd(digit, 1);
}

static void	ft_int_dot(t_flags flags)
{
	int	dot;

	dot = flags.dot;
	if (flags.sign == 1)
	{
		write(1, "-", 1);
		while ((dot--) - (flags.len - 1))
			write(1, "0", 1);
	}
	else
	{
		while (dot-- != flags.len)
			write(1, "0", 1);
	}
}

static void	ft_int_width(t_flags flags, int width)
{
	if (flags.dot >= flags.len && flags.dot <= width && flags.sign == 1)
	{
		while (width-- != flags.dot + 1)
			write(1, " ", 1);
	}
	else if (flags.dot >= flags.len && flags.dot <= width && flags.sign == 0)
	{
		while (width-- != flags.dot)
			write(1, " ", 1);
	}
	else if (flags.zero == 1 && flags.dot < 0)
	{
		if (flags.sign == 1)
			write(1, "-", 1);
		while (width-- != flags.len)
			write(1, "0", 1);
	}
	else if (flags.dot < flags.len)
	{
		while (width-- != flags.len)
			write(1, " ", 1);
	}
}

static int	ft_count(t_flags flags, int count, int d)
{
	if (flags.width > flags.len && flags.width > flags.dot)
		count = flags.width;
	else if (flags.dot > flags.len && flags.dot > flags.width && d >= 0)
		count = flags.dot;
	else if (flags.dot >= flags.len && flags.dot > flags.width && d < 0)
		count = flags.dot + 1;
	else
		count = flags.len;
	return (count);
}

int	ft_integer(va_list ap, t_flags flags, int count)
{
	int		d;
	int		width;
	char	*digit;

	width = flags.width;
	d = va_arg(ap, int);
	if (d == 0 && flags.width == 0 && flags.dot == 0)
		return (count);
	digit = ft_itoa(d);
	flags.len = ft_strlen(digit);
	if (d < 0)
		flags.sign = 1;
	if (flags.width > flags.len && flags.minus == 0)
		ft_int_width(flags, width);
	if (flags.dot >= flags.len)
		ft_int_dot(flags);
	ft_print_int(digit, flags);
	if (flags.width > flags.len && flags.minus == 1)
		ft_int_width(flags, width);
	if (digit)
		free(digit);
	return (ft_count(flags, count, d));
}
