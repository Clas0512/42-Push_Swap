#include "push_swap.h"

void    ft_rrr(t_stack *stack)
{
    ft_rra(stack);
    ft_rrb(stack);
}

void    ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

int ft_counter_of_num(char *str)
{
    int i;
    int result;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            result++;
        i++;
    }
    return (result);
}

int ft_general_check(char *str)
{
    int     i;
    char    c;

    i = 0;
    while (str[i] != '\0')
    {
        c = str[i];
        if (c != ' ' && c != '-' && !('0' <= c && c <= '9'))
            return (0);
        if (!(c == '-' && ('0' <= str[i + 1] && str[i + 1] <= '9')) && !(i > 0 && c == '-' &&
            (str[i - 1] == ' ')))
            return (0);
        i++;
    }
    return (1);
}

void    ft_check_arg(int ac, char **argv, t_stack *stacks)
{
    int i;
    int num_c;

    num_c = 0;
    i = 1;

    while (i < ac)
    {
        if (!ft_general_check(argv[i]))
            ft_error();
        num_c += ft_counter_of_num(argv[i]);
        i++;
    }
    if (num_c == 0)
        ft_error();
    stacks->a = malloc(sizeof(int) * i);
    stacks->b = malloc(sizeof(int) * i);
}

int main(int ac, char **av)
{
    t_stack stacks;

    ft_check_arg(ac, av, &stacks);
    
    return (0);
}
