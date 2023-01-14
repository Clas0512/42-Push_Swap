#include "push_swap.h"

long	ft_atol(char *str)
{
	int		sign;
	int		i;
	long	r;

	i = -1;
	sign = 1;
	r = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '-' && str[i + 1] == '0')
			ft_error();
		if (str[i] == ' ')
			ft_error();
		if (str[i] == '-')
		{
			sign *= -1;
			continue ;
		}
		r = r * 10 + (str[i] - '0');
	}
	r *= sign;
	if (r < -2147483648 || r > 2147483647)
		ft_error();
	return (r);
}

void	ft_set_stack(t_stack *stacks, int ac, char **av)
{
	int		i;
	int		j;
	char	**rstr;
	int		cu;
	int		siu;

	cu = stacks->a_size - 1;
	i = ac - 1;
	while (i > 0)
	{
		j = stacks->each_arg_c[i] - 1;
		rstr = ft_split(av[i], ' ');
		while (j >= 0)
		{
			stacks->a[cu] = ft_atol(rstr[j]);
			cu--;
			j--;
		}
		i--;
		siu = -1;
		while (rstr[++siu])
			free(rstr[siu]);
		free(rstr);
	}
}

int	ft_is_sorted(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a_size - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}
