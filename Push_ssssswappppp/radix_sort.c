/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:33:17 by anargul           #+#    #+#             */
/*   Updated: 2023/01/15 00:21:59 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_to_bit(t_stack *stack, int j)
{
	if (((stack->a[0] >> j) & 1) == 0)
		ft_pb(stack);
	else
		ft_ra(stack);
}

void	radix_sort(t_stack *stack)
{
	int	j;
	int	i;
	int	bit_size;
	int	size;

	bit_size = 8;
	if (stack->a_size == 100)
		bit_size = 6;
	i = 0;
	j = 0;
	while (j <= bit_size)
	{
		i = 0;
		size = stack->a_size;
		while (i < size)
		{
			change_to_bit(stack, j);
			i++;
		}
		while (stack->b_size != 0)
			ft_pa(stack);
		j++;
	}
}
