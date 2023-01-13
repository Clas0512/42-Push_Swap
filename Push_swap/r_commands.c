#include "push_swap.h"

void ft_ra(t_stack *stack)
{
    int     i;
    int     tmp;

    if (stack->a_size > 1)
    {
        tmp = stack->a[0];
        i = 0;
        while (i < stack->a_size - 1)
        {
            stack->a[i] = stack->a[i + 1];
            i++;
        }
        stack->a[stack->a_size - 1] = tmp;
    }
}

void ft_rb(t_stack *stack)
{
    int     i;
    int     tmp;

    if (stack->b_size > 1)
    {
        tmp = stack->b[0];
        i = 0;
        while (i < stack->b_size - 1)
        {
            stack->b[i] = stack->b[i + 1];
            i++;
        }
        stack->b[stack->b_size - 1] = tmp;
    }
}

void ft_rr(t_stack *stack)
{
    ft_ra(stack);
    ft_rb(stack);
}
