#include "ft_printf.h"

int	ft_parse_type(va_list ap, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.type == 'c' || flags.type == '%')
		return (ft_char(ap, flags, count));
	if (flags.type == 's')
		return (ft_string(ap, flags, count));
	if (flags.type == 'd' || flags.type == 'i')
		return (ft_integer(ap, flags, count));
	if (flags.type == 'u')
		return (ft_unsigned(ap, flags, count));
	if (flags.type == 'x' || flags.type == 'X')
		return (ft_hex(ap, flags, count));
	if (flags.type == 'p')
		return (ft_pointr(ap, flags, count));
	return (count);
}
