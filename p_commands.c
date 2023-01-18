/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:33:11 by anargul           #+#    #+#             */
/*   Updated: 2023/01/16 20:38:54 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stacks *stacks)
{
	int	i;

	if (stacks->b_size > 0)
	{
		i = stacks->a_size;
		while (i > 0)
		{
			stacks->a[i] = stacks->a[i - 1];
			i--;
		}
		stacks->a[0] = stacks->b[0];
		i = 0;
		while (i < stacks->b_size - 1)
		{
			stacks->b[i] = stacks->b[i + 1];
			i++;
		}
		stacks->b_size--;
		stacks->a_size++;
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_stacks *stacks)
{
	int	i;

	if (stacks->a_size > 0)
	{
		i = stacks->b_size;
		while (i > 0)
		{
			stacks->b[i] = stacks->b[i - 1];
			i--;
		}
		stacks->b[0] = stacks->a[0];
		i = 0;
		while (i < stacks->a_size - 1)
		{
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->a_size--;
		stacks->b_size++;
		write(1, "pb\n", 3);
	}
}
