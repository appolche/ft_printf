#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		stardot;
	int		len;
	int		sign;
	char	type;
}			t_flags;

int		ft_printf(const char *c, ...);
int		ft_parse_format_string(const char *format, va_list ap, int count);
int		ft_parse_flag(const char *str, va_list ap, int i, t_flags *flags);
int		ft_char(va_list ap, t_flags flags, int count);
int		ft_parse_type(va_list ap, t_flags flags);
int		ft_find_type(char c, char *str);
int		ft_stardot(const char *str, va_list ap, int i);
int		ft_string(va_list ap, t_flags flags, int count);
int		ft_integer(va_list ap, t_flags flags, int count);
int		ft_unsigned(va_list ap, t_flags flags, int count);
int		ft_hex(va_list ap, t_flags flags, int count);
int		ft_pointr(va_list ap, t_flags flags, int count);
char	*ft_itoa_unsigned(unsigned int nb);
char	*ft_itoa_hex(unsigned long long n, t_flags flags);

#endif
