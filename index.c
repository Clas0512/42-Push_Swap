#include "push_swap.h"

void	find_plcs(int *temp, t_stacks *stacks)
{
	int	i;
	int	p;
	int	j;
	int	*indexd;

	indexd = malloc(sizeof(int) * stacks->a_size);
	i = 0;
	while (i < stacks->a_size)
	{
		j = 0;
		p = stacks->a[i];
		while (j < stacks->a_size)
		{
			if (temp[j] == p)
				indexd[i] = j;
				j++;
		}
		i++;
	}
	free(temp);
	free(stacks->a);
	stacks->a = indexd;
	free(indexd);
}

void	fake_sort(int *temp, t_stacks *stacks)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < stacks->a_size - 1)
	{
		if (temp[i] > temp[i + 1])
		{
			tmp = temp[i];
			temp[i] = temp[i + 1];
			temp[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	find_plcs(temp, stacks);
}

void	ft_index(t_stacks *stacks)
{
	int	*temp;
	int	i;

	i = 0;
	temp = malloc(sizeof(int) * stacks->a_size);
	while (i < stacks->a_size)
	{
		temp[i] = stacks->a[i];
		i++;
	}
	fake_sort(temp, stacks);
}