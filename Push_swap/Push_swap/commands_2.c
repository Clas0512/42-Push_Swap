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

void ft_rra(t_stack *stack)
{
    int     i;
    int     tmp;

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
    }
}

void ft_rrb(t_stack *stack)
{
    int     i;
    int     tmp;

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
    }
}
