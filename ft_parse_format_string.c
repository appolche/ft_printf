#include "ft_printf.h"

static t_flags	ft_reset_flags(t_flags flags)
{
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.type = 0;
	flags.width = 0;
	flags.len = 0;
	flags.sign = 0;
	flags.stardot = 0;
	return (flags);
}

static int	ft_skip_space(const char *format, int i)
{
	if (format[i] == ' ')
	{
		while (format[i] == ' ')
			i++;
	}
	return (i);
}

int	ft_parse_format_string(const char *format, va_list ap, int count)
{
	t_flags	flags;
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			flags = ft_reset_flags(flags);
			i = ft_skip_space(format, i);
			i = ft_parse_flag(format, ap, i, &flags);
			count += ft_parse_type(ap, flags);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	return (count);
}
