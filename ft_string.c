#include "ft_printf.h"

static int	ft_counter(t_flags flags, int count)
{
	int	width;

	width = flags.width;
	if (flags.width < 0)
		width = flags.width * (-1);
	if (width > flags.len || (width > flags.dot && flags.dot >= 0)
		|| (width > 0 && flags.dot == 0))
		count = width;
	else if (flags.dot < flags.len && flags.dot > 0 && width < flags.dot)
		count = flags.dot;
	else
		count = flags.len;
	return (count);
}

static void	ft_str_width(t_flags flags)
{
	int	width;

	width = flags.width;
	if (width > flags.dot && flags.dot < flags.len && flags.dot > 0)
	{
		while (width-- != flags.dot)
			write(1, " ", 1);
	}
	else if (width > flags.len && (flags.dot >= flags.len || flags.dot < 0))
	{
		while (width-- != flags.len)
			write(1, " ", 1);
	}
	else if (width > 0 && flags.dot == 0)
	{
		while (width--)
			write(1, " ", 1);
	}
}

static void	ft_print_str(t_flags flags, char *str)
{
	int	dot;
	int	i;

	i = 0;
	dot = flags.dot;
	if (flags.dot >= flags.len || flags.dot < 0)
		ft_putstr_fd(str, 1);
	else if (flags.dot < flags.len && flags.dot > 0)
	{
		while (dot--)
			write(1, &(str[i++]), 1);
	}
}

int	ft_string(va_list ap, t_flags flags, int count)
{
	char	*str;

	str = va_arg(ap, char *);
	if (flags.width == 0 && flags.dot == 0)
		return (count);
	if (!str)
	{
		str = "(null)";
		flags.len = 6;
	}
	else
		flags.len = ft_strlen(str);
	if (flags.minus == 0)
		ft_str_width(flags);
	ft_print_str(flags, str);
	if (flags.minus == 1)
		ft_str_width(flags);
	count = ft_counter(flags, count);
	return (count);
}
