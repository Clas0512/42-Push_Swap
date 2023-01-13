#include "push_swap.h"

void    ft_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

int find_plc(int i, t_stack *stacks)
{
    int j;
    int min;
    int plc;

    min = stacks->a[i];
    plc = i;
    j = 0;
    while (j < stacks->a_size)
    {
        if (min > stacks->a[j])
        {
            min = stacks->a[j];
            plc = j;
        }
        j++;
    }
    stacks->a[plc] = 2147483647;
    return (plc);
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
    while (i < stacks->a_size)
    {
        plc = find_plc(i, stacks);
        temp[plc] = sc;
        i++;
        sc++;
    }
    free(stacks->a);
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
    ft_index(&stacks);
	for (size_t i = 0; i < stacks.a_size; i++)
		printf("%d\n", stacks.a[i]);
	printf("\n\n\n");
	ft_sorting(&stacks);
	printf("\n\n\n");
	for (size_t i = 0; i < stacks.a_size; i++)
		printf("%d\n", stacks.a[i]);
	
    return (0);
}
