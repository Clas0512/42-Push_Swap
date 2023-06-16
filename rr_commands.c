#include "push_swap.h"

void	ft_rra(t_stacks *stacks)
{
	int	i;
	int	tmp;

	if (stacks->a_size > 1)
	{
		tmp = stacks->a[stacks->a_size - 1];
		i = stacks->a_size - 1;
		while (i > 0)
		{
			stacks->a[i] = stacks->a[i - 1];
			i--;
		}
		stacks->a[0] = tmp;
		write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_stacks *stacks)
{
	int	i;
	int	tmp;

	if (stacks->b_size > 1)
	{
		tmp = stacks->b[stacks->b_size - 1];
		i = stacks->b_size - 1;
		while (i > 0)
		{
			stacks->b[i] = stacks->b[i - 1];
			i--;
		}
		stacks->b[0] = tmp;
		write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_stacks *stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
	write(1, "rrr\n", 4);
}
