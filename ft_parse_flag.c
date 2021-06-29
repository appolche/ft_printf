#include "ft_printf.h"

static int	ft_dot_init(const char *format, va_list ap, int i, t_flags *flags)
{
	i++;
	if (format[i] == '*' || (format[i] >= '0' && format[i] <= '9'))
		flags->dot = ft_stardot(format, ap, i);
	else
	{
		flags->dot = 0;
		i--;
	}
	return (i);
}

static int	ft_if_stardot(const char *format, va_list ap, int i, t_flags *flags)
{
	if (format[i] == '*' || ((format[i] >= '0' && format[i] <= '9')
			&& flags->width == 0 && flags->stardot == 0))
	{
		flags->width = ft_stardot(format, ap, i);
		if (flags->width < 0)
		{
			flags->width *= (-1);
			flags->minus = 1;
			flags->zero = 0;
		}
	}
	if (format[i] == '.')
	{
		flags->stardot = 1;
		i = ft_dot_init(format, ap, i, flags);
	}
	return (i);
}

int	ft_parse_flag(const char *format, va_list ap, int i, t_flags *flags)
{
	int	j;

	j = 0;
	while (format[i])
	{
		if (format[i] == '0' && j == 0)
			flags->zero = 1;
		if (format[i] == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		i = ft_if_stardot(format, ap, i, flags);
		if (ft_find_type(format[i], "cspdiuxX%"))
		{
			flags->type = format[i];
			break ;
		}
		i++;
		j++;
	}
	return (i);
}
