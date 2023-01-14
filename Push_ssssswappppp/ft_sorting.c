#include "push_swap.h"

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
	if (stack->a[0] == 3)
		extra(stack);
	else if (stack->a[1] == 3)
	{
		ft_sa(stack);
		four_sort(stack);
	}
	else if (stack->a[2] == 3)
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

void	five_sort(t_stack *stack)
{
	if (!ft_is_sorted(stack))
		return;
	if (stack->a[0] == 3 || (stack->a_size == 4))
	{
		if (stack->a_size == 5)
			ft_pb(stack);
		if (stack->a[0] == 4)
		{
			ft_pb(stack);
			three_sort(stack);
			ft_pa(stack);
			ft_pa(stack);
			ft_ra(stack);
			ft_ra(stack);
		}
		else
		{
			if (stack->a[1] == 4)
				ft_ra(stack);
			else
				ft_rra(stack);
			five_sort(stack);
		}
	}
	else if (stack->a_size > 3)
	{
		if (stack->a[1] == 3)
			ft_ra(stack);
		else
			ft_rra(stack);
		five_sort(stack);
	}
}


void	ft_sorting(t_stack *stack)
{
	int	size;

	size = stack->a_size;
	if (size == 2)
		ft_sa(stack);
	if (size == 3)
		three_sort(stack);
	if (size == 4)
		four_sort(stack);
	if (size == 5)
		five_sort(stack);
}
