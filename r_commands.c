#include "push_swap.h"

void	ft_ra(t_stacks *stacks)
{
	int	i;
	int	tmp;

	if (stacks->a_size > 1)
	{
		tmp = stacks->a[0];
		i = 0;
		while (i < stacks->a_size - 1)
		{
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->a[stacks->a_size - 1] = tmp;
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_stacks *stacks)
{
	int	i;
	int	tmp;

	if (stacks->b_size > 1)
	{
		tmp = stacks->b[0];
		i = 0;
		while (i < stacks->b_size - 1)
		{
			stacks->b[i] = stacks->b[i + 1];
			i++;
		}
		stacks->b[stacks->b_size - 1] = tmp;
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_stacks *stacks)
{
	ft_ra(stacks);
	ft_rb(stacks);
	write(1, "rr\n", 3);
}
