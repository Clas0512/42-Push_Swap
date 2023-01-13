#include "push_swap.h"

void    ft_sa(t_stack *stack)
{
    int     tmp;

    if (stack->a_size > 1)
    {
        write(1, "sa\n", 3);
        tmp = stack->a[0];
        stack->a[0] = stack->a[1];
        stack->a[1] = tmp;
    }
}

void    ft_sb(t_stack *stack)
{
    int     tmp;

    if (stack->b_size > 1)
    {
		write(1, "sb\n", 3);
        tmp = stack->b[0];
        stack->b[0] = stack->b[1];
        stack->b[1] = tmp;
    }
}

void    ft_ss(t_stack *stack)
{
    ft_sa(stack);
    ft_sb(stack);
	write(1, "ss\n", 3);
}
