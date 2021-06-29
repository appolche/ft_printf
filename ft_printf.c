#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		ap;

	count = 0;
	va_start(ap, format);
	count = ft_parse_format_string(format, ap, count);
	va_end(ap);
	return (count);
}
