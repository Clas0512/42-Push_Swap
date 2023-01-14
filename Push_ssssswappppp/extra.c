#include "push_swap.h"

void	five_sort_extra(t_stack *stack)
{
	ft_pb(stack);
	three_sort(stack);
	ft_pa(stack);
	ft_pa(stack);
	ft_ra(stack);
	ft_ra(stack);
}

void	extra(t_stack *stack)
{
	ft_pb(stack);
	three_sort(stack);
	ft_rrb(stack);
	ft_pa(stack);
	ft_ra(stack);
}
