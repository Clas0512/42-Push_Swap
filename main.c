#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac == 1)
		exit(1);
	ft_check_arg(ac, av, &stacks);
	ft_set_stacks(&stacks, ac, av);
	ft_isthr_cpy(&stacks);
	if (!ft_is_sorted(&stacks))
		exit(1);
	ft_index(&stacks);
	ft_sorting(&stacks);
	return (0);
}
