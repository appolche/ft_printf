#include "ft_printf.h"

static int	malloc_size(const char *str, int i, int j)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		j++;
	}
	return (j);
}

int	ft_stardot(const char *str, va_list ap, int i)
{
	int		j;
	int		flag;
	char	*tmp;

	j = 0;
	if (str[i] == '*')
		flag = va_arg(ap, int);
	else
	{
		tmp = malloc((malloc_size(str, i, j) + 1) * sizeof(char));
		if (tmp == NULL)
			return (0);
		while (str[i] >= '0' && str[i] <= '9')
		{
			tmp[j] = str[i];
			i++;
			j++;
		}
		tmp[j] = '\0';
		flag = ft_atoi(tmp);
		free(tmp);
	}
	return (flag);
}
