#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	find_plcs(int *temp, t_stack *stack)
{
	int	i;
	int	p;
	int	j;
	int	*indexd;

	indexd = malloc(sizeof(int) * stack->a_size);
	i = 0;
	while (i < stack->a_size)
	{
		j = 0;
		p = stack->a[i];
		while (j < stack->a_size)
		{
			if (temp[j] == p)
				indexd[i] = j;
				j++;
		}
		i++;
	}
	free(temp);
	free(stack->a);
	stack->a = indexd;
	free(indexd);
}

void	fake_sort(int *temp, t_stack *stack)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < stack->a_size - 1)
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
	find_plcs(temp, stack);
}

void	ft_index(t_stack *stacks)
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

int	main(int ac, char **av)
{
	t_stack	stacks;

	if (ac == 1)
		exit(1);
	ft_check_arg(ac, av, &stacks);
	ft_set_stack(&stacks, ac, av);
	ft_isthr_cpy(&stacks);
	if (!ft_is_sorted(&stacks))
		exit(1);
	stacks.sign = malloc(sizeof(int) * stacks.a_size);
	stacks.sign_size = stacks.a_size;
	ft_index(&stacks);
	ft_sorting(&stacks);
	return(0);
}
