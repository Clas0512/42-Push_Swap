#include "push_swap.h"

void	ft_rra(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->a_size > 1)
	{
		tmp = stack->a[stack->a_size - 1];
		i = stack->a_size - 1;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = tmp;
		write(1, "rra\n", 4);
	}
}

void	ft_rrb(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->b_size > 1)
	{
		tmp = stack->b[stack->b_size - 1];
		i = stack->b_size - 1;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = tmp;
		write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_stack *stack)
{
	ft_rra(stack);
	ft_rrb(stack);
	write(1, "rrr\n", 4);
}
