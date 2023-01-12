#include "push_swap.h"

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

void    ft_index(t_stack *stacks)
{
    int *temp;
    int i;
    int j;
    static int sc;
    int min;
    int plc;

    plc = 0;
    temp = malloc(sizeof(int) * stacks->a_size);
    if (!temp)
        ft_error();
    i = 0;
    while (i < stacks->a_size - 1)
    {
        min = stacks->a[i];
        j = 0;
        while (j < stacks->a_size - 1)
        {
            if (min > stacks->a[j])
            {
                min = stacks->a[j];
                plc = j;
            }
            j++;
        }
        stacks->a[plc] = 23234;
        temp[plc] = sc;
        i++;
        sc++;
    }
    stacks->a = temp;
    free(temp);
}

int main(int ac, char **av)
{
    t_stack stacks;

    ft_check_arg(ac, av, &stacks);
    ft_set_stack(&stacks, ac, av);
    ft_isthr_cpy(&stacks);
    if (!ft_is_sorted(&stacks))
        exit(1);
    // for (size_t i = 0; i < stacks.a_size; i++)
    //     printf("%d\n", stacks.a[i]);
    ft_index(&stacks);
     printf("\n\n\n");
     for (size_t i = 0; i < stacks.a_size; i++)
         printf("%d\n", stacks.a[i]);
    return (0);
}
