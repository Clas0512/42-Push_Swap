#include "push_swap.h"

int ft_count_of_num(char *str, t_stack *stacks, int ac)
{
    int i;
    int result;

    result = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            result++;
        i++;
    }
    stacks->each_arg_c[ac] = result;
    return (result);
}

int ft_general_check(char *str)
{
    int     i;
    char    c;
    int     s;

    s = 0;
    i = 0;
    while (str[i] != '\0')
    {
        c = str[i];
        if (c != ' ' && c != '-' && !('0' <= c && c <= '9'))
            return (0);
        if ((c == '-' && !('0' <= str[i + 1] && str[i + 1] <= '9')) || (i > 0 && c == '-' && !(str[i - 1] == ' ')))
            return (0);
        c++;
        i++;
    }
    if (c == 0) // **************************
        return (0); // sadece boşluk varsa kontrolü
    return (1);
}

void ft_isthr_cpy(t_stack *stacks)
{
    int p;
    int i;
    int j;
    int numc;

    i = 0;
    while (i < stacks->a_size)
    {
        p = stacks->a[i];
        j = 0;
        numc = 0;
        while (j < stacks->a_size)
        {
            if (p == stacks->a[j])
                numc++;
            
            if (numc > 1)
                ft_error();
            j++;
        }
        i++;
    }
}

void    ft_check_arg(int ac, char **argv, t_stack *stacks)
{
    int i;
    int num_c;
    
    stacks->each_arg_c = malloc(sizeof(int) * ac);
    num_c = 0;
    i = 1;
    while (i < ac)
    {
        if (!*argv[i])
            ft_error();
        if (!ft_general_check(argv[i]))
            ft_error();
        num_c += ft_count_of_num(argv[i], stacks, i);
        i++;
    }
    if (num_c == 0)
        ft_error();
    stacks->a = malloc(sizeof(int) * num_c);
    if (!stacks->a)
        ft_error();
    stacks->b = malloc(sizeof(int) * num_c);
    if (!stacks->b)
        ft_error();
    stacks->a_size = num_c;
    stacks->b_size = num_c;
}

long    ft_atol(char *str)
{
    long    r;
    int     sign;
    int     i;

    i = -1;
    sign = 1;
    r = 0;
    while (str[++i] != '\0')
    {
        if (str[i] == '-' && str[i + 1] == '0')
            ft_error();
        if (str[i] == ' ')
            ft_error();
        if (str[i] == '-')
        {
            sign *= -1;
            continue;
        }
        r = r * 10 + (str[i] - '0');
    }
    r *= sign;
    if (r < -2147483648 || r > 2147483647)
        ft_error();
    return (r);
}

void    ft_set_stack(t_stack *stacks, int ac, char **av)
{
    int     i;
    int     j;
    char    **rstr;
    int     cu;
    int     siu;

    cu = stacks->a_size - 1;
    i = ac - 1;
    while (i > 0)
    {
        j = stacks->each_arg_c[i] - 1;
        rstr = ft_split(av[i], ' ');
        while (j >= 0)
        {
            stacks->a[cu] = ft_atol(rstr[j]);
            cu--;
            j--;
        }
        i--;
        siu = -1;
        while (rstr[++siu])
            free(rstr[siu]);
        free(rstr);
    }
}

int    ft_is_sorted(t_stack *stacks)
{
    int i;

    i = 0;
    while (i < stacks->a_size - 1)
    {
        if (stacks->a[i] > stacks->a[i + 1])
            return (1);
        i++;
    }
    return (0);
}