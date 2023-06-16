#include "libft.h"

int	size_calc(long nb)
{
	int	counter;

	counter = 0;
	if (nb < 0)
	{
		nb *= -1;
		counter++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		counter++;
	}
	counter++;
	return (counter);
}

void	convert_number(long nb, char *c, int *i)
{
	if (nb < 0)
	{
		nb *= -1;
		*c = '-';
		*i += 1;
	}
	if (nb >= 10)
	{
		convert_number(nb / 10, c, i);
		convert_number(nb % 10, c, i);
	}
	else
	{
		*(c + *i) = nb + '0';
		*i += 1;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*str;
	int		size;
	int		i;

	i = 0;
	nb = n;
	size = size_calc(nb);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	convert_number(nb, str, &i);
	str[i] = '\0';
	return (str);
}
