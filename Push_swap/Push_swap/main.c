#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// void    ft_rrr(t_stack *stack)
// {
//     ft_rra(stack);
//     ft_rrb(stack);
// }

void    ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

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

    i = 0;
    while (str[i] != '\0')
    {
        c = str[i];
        if (c != ' ' && c != '-' && !('0' <= c && c <= '9'))
            return (0);
        if ((c == '-' && !('0' <= str[i + 1] && str[i + 1] <= '9')) || (i > 0 && c == '-' && !(str[i - 1] == ' ')))
            return (0);
        i++;
    }
    return (1);
}

void ft_isthr_cpy(t_stack *stacks)
{
    int p;
    int i;
    int j;
    int numc;

    i = 0;
    numc = 0;
    while (i < stacks->a_size)
    {
        p = stacks->a[i];
        printf("%d\n", stacks->a[0]);
        printf("%d\n", stacks->a[1]);
        printf("%d\n", stacks->a[2]);
        j = 0;
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
    printf("%d\n", numc);
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
    if (r == -2147483648 || r == 2147483647)
        ft_error();
    return (r);
}

// char *ft_fx(int i, int j, char *str)
// {
//     char *returnn;
//     int c;

//     returnn = malloc(sizeof(char) * ((j - i) + 1));
//     c = 0;
//     while (i < j)
//         returnn[c++] = str[i++];
//     return(returnn);
// }

char    **ft_split(char *str, t_stack *stacks, int n)
{
    char    **returnn;
    int     i;
    int     c;
    int     j;
    int     cu;

    cu = 0;
    c = stacks->each_arg_c[n];
    returnn = malloc(sizeof(char *) * (c + 1));
    returnn[c] = NULL;
    c -= 1; 
    i = 0;
    while (str[i] != '\0' )
    {
        j = 0;
        while (str[i] != ' ' && str[i] != '\0')
        {
            while (str[i] != ' ' && str[i] != '\0')
                cu++;
            returnn[c] = malloc(sizeof(char) * (cu + 1));
            returnn[c--][j++] = str[i++];
        }
        i++;
    }
    return (returnn);
}

void    ft_set_stack(t_stack *stacks, int ac, char **av)
{
    int     i;
    int     j;
    char    **rstr;
    int     cu;

    cu = stacks->a_size - 1;
    i = ac;
    while (i > 1)
    {
        rstr = ft_split(av[i], stacks, i);
        j = stacks->each_arg_c[i] - 1;
        while (rstr[i][j])
            stacks->a[cu--] = (int)ft_atol(rstr[j--]);
        i--;
    }
} 

int main(int ac, char **av)
{
    t_stack stacks;

    ft_check_arg(ac, av, &stacks);
    ft_set_stack(&stacks, ac, av);
    ft_isthr_cpy(&stacks);
    return (0);
}
