/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:33:17 by anargul           #+#    #+#             */
/*   Updated: 2023/01/16 20:38:54 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_to_bit(t_stacks *stacks, int j)
{
	if (((stacks->a[0] >> j) & 1) == 0)
		ft_pb(stacks);
	else
		ft_ra(stacks);
}

void	radix_sort(t_stacks *stacks)
{
	int	j;
	int	i;
	int	bit_size;
	int	size;

	bit_size = 8;
	if (stacks->a_size == 100)
		bit_size = 6;
	i = 0;
	j = 0;
	while (j <= bit_size)
	{
		i = 0;
		size = stacks->a_size;
		while (i < size)
		{
			change_to_bit(stacks, j);
			i++;
		}
		while (stacks->b_size != 0)
			ft_pa(stacks);
		j++;
	}
}
