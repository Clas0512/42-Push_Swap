/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_commands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:33:11 by anargul           #+#    #+#             */
/*   Updated: 2023/01/14 21:33:12 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *stack)
{
	int	i;

	if (stack->b_size > 0)
	{
		i = stack->a_size;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = stack->b[0];
		i = 0;
		while (i < stack->b_size - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b_size--;
		stack->a_size++;
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_stack *stack)
{
	int	i;

	if (stack->a_size > 0)
	{
		i = stack->b_size;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = stack->a[0];
		i = 0;
		while (i < stack->a_size - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a_size--;
		stack->b_size++;
		write(1, "pb\n", 3);
	}
}
