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

int ft_count_of_num(char *str)
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
        if (!(c == '-' && ('0' <= str[i + 1] && str[i + 1] <= '9')) && !(i > 0 && c == '-' && (str[i - 1] == ' ')))
            return (0);
        i++;
    }
    return (1);
}

int ft_isthr_cpy(t_stack *stacks)
{
    int p;
    int i;
    int j;
    int numc;

    i = 0;
    p = 0;
    numc = 0;
    while (i < stacks->a_size)
    {
        p = stacks->a[i];
        j = 0;
        while (j < stacks->a_size)
        {
            if (p == stacks->a[j])
                numc++;
            j++;
        }
        i++;
    }
    if (numc > 1)
        return (0);
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
        num_c += ft_count_of_num(argv[i]);
        i++;
    }
    if (num_c == 0)
        ft_error();
    stacks->a = malloc(sizeof(int) * num_c);
    stacks->b = malloc(sizeof(int) * num_c);
    stacks->a_size = num_c;
    stacks->b_size = num_c;
}

long    ft_atol(char *str)
{
    long    r;
    int     i;
    int     sign;

    i = -1;
    sign = 1;
    r = 0;
    while (str[++i] != '\0')
    {
        if (str[i] == ' ')
            ft_error();
        if (str[i] == '-')
        {
            sign *= -1;
            continue;
        }
        r += str[i] - 48;
        r *= 10;
    }
    r /= 10;
    r *= sign;
    return (r);
}

char    **ft_split(char **str, s_stack *stacks)
{
    int i;
    int j;
    char **r_str;

    r_str = malloc(stacks->a_size + 1);
    i = -1;
    j = 0;
    while (str[++i] != '\0')
    {
        if (str[i] == ' ')
            continue;
        while (str[i] != ' ' && str[i] != '\0')
        {
            
        }
        j++;
    }
    
}

int ft_isthr_space(char **str)
{
    int i;
    int v;
    int j;

    v = 0;
    i = -1;
    while (str[++i])
    {
        if (str[i] == ' ')
            continue;
        else
        {
            j = 0;
            while (str[i + j] != ' ' && str[i + j] != '\0')
            {
                if (str[i + j] == '-')
                    
                i++;
                j++;
            }
            
        }
    }
    
}

void    ft_set_stack(t_stack *stacks, int ac, char **av)
{
    int     i;
    int     j; 
    char    **parsed;

    parsed = ft_split(av, &stacks);
    i = 1;
    j = 0;
    while (i < ac)
    {
        if (av)
        {
            char **spl = ft_split(av[i], " ");
            whil
        } else {
            stacks->a[i] = atoi(av[i]);
        }
        i++;
    }
}

int main(int ac, char **av)
{
    t_stack stacks;

    ft_check_arg(ac, av, &stacks);
    ft_set_stack(&stacks, ac, av);
    return (0);
}
