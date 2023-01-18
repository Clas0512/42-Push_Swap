/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:33:20 by anargul           #+#    #+#             */
/*   Updated: 2023/01/16 20:38:54 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks *stacks)
{
	int	tmp;

	if (stacks->a_size > 1)
	{
		write(1, "sa\n", 3);
		tmp = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = tmp;
	}
}

void	ft_sb(t_stacks *stacks)
{
	int	tmp;

	if (stacks->b_size > 1)
	{
		write(1, "sb\n", 3);
		tmp = stacks->b[0];
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = tmp;
	}
}

void	ft_ss(t_stacks *stacks)
{
	ft_sa(stacks);
	ft_sb(stacks);
	write(1, "ss\n", 3);
}
