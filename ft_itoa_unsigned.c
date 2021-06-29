#include "ft_printf.h"

static unsigned int	len(unsigned int nb)
{
	int	len;

	len = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_null(unsigned int nb, char *str)
{
	if (nb == 0)
		str[0] = '0';
	return (str);
}

char	*ft_itoa_unsigned(unsigned int nb)
{
	int		i;
	char	*str;

	i = len(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (NULL == str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		return (ft_null(nb, str));
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[i] = '0' + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (str);
}
