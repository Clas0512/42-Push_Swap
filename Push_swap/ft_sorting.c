#include "push_swap.h"

void	ft_sorting(t_stack *stack)
{
	int	size;

	size = stack->a_size;
	if(size == 2)
		ft_sa(stack);
	else if(size == 3)
		three_sort(stack);
	else if(size == 4)
		four_sort(stack);
	else
		radix_sort(stack);
}

void	three_sort(t_stack *stack)
{
	if (!ft_is_sorted(stack))
		return;
	if (stack->a[0] == 2)
	{
		ft_ra(stack);
		if (stack->a[1] == 0)
			ft_sa(stack);
	}
	else if (stack->a[1] == 2)
	{
		ft_rra(stack);
		if (stack->a[1] == 0)
			ft_sa(stack);
	}
	else if (stack->a[2] == 2)
	{
		ft_sa(stack);
	}
}

void	extra(t_stack *stack)
{
	ft_pb(stack);
	three_sort(stack);
	ft_rrb(stack);
	ft_pa(stack);
	ft_ra(stack);
}
void	four_sort(t_stack *stack)
{
	if(stack->a[0] == 3)
		extra(stack);
	else if(stack->a[1] == 3)
	{
		ft_sa(stack);
		four_sort(stack);
	}
	else if(stack->a[2] == 3)
	{
		ft_rra(stack);
		four_sort(stack);
	}
	else
	{
		ft_rra(stack);
		four_sort(stack);
	}
}

void	change_to_bit(t_stack *stack, int j)
{
	if (((stack->a[0] >> j) & 1) == 0)
		ft_pb(stack);
	else
		ft_ra(stack);
}

void	radix_sort(t_stack *stack)
{
	int	j;
	int	i;
	int	bit_size;
	int	size;

	i = 0;
	j = 0;
	bit_size = 8;
	if (stack->a_size == 100)
	{
		bit_size = 6;
	}
	while (j <= bit_size)
	{
		i = 0;
		size = stack->a_size;
		while (i < size)
		{
			change_to_bit(stack, j);
			i++;
		}
		while (stack->b_size != 0)
			ft_pa(stack);
		j++;
	}
}