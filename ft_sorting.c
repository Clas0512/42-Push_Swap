/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:32:58 by anargul           #+#    #+#             */
/*   Updated: 2023/01/14 21:32:59 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack *stack)
{
	if (!ft_is_sorted(stack))
		return ;
	if (stack->a[0] == 2)
	{
		ft_ra(stack);
		if (stack->a[1] == 0)
			ft_sa(stack);
	}
	else if (stack->a[1] == 2)
	{
		ft_rra(stack);
		if (stack->a[1] == 0)
			ft_sa(stack);
	}
	else if (stack->a[2] == 2)
	{
		ft_sa(stack);
	}
}

void	four_sort(t_stack *stack)
{
	if (stack->a[0] == 3)
		extra(stack);
	else if (stack->a[1] == 3)
	{
		ft_sa(stack);
		four_sort(stack);
	}
	else if (stack->a[2] == 3)
	{
		ft_rra(stack);
		four_sort(stack);
	}
	else
	{
		ft_rra(stack);
		four_sort(stack);
	}
}

void	five_sort(t_stack *stack)
{
	if (stack->a[0] == 3 || (stack->a_size == 4))
	{
		if (stack->a_size == 5)
			ft_pb(stack);
		if (stack->a[0] == 4)
			five_sort_extra(stack);
		else
		{
			if (stack->a[1] == 4)
				ft_ra(stack);
			else
				ft_rra(stack);
			five_sort(stack);
		}
	}
	if (!ft_is_sorted(stack))
		return ;
	else if (stack->a_size > 3)
	{
		if (stack->a[1] == 3)
			ft_ra(stack);
		else
			ft_rra(stack);
		five_sort(stack);
	}
}

void	ft_sorting(t_stack *stack)
{
	int	size;

	size = stack->a_size;
	if (size == 2)
		ft_sa(stack);
	else if (size == 3)
		three_sort(stack);
	else if (size == 4)
		four_sort(stack);
	else if (size == 5)
		five_sort(stack);
	else
		radix_sort(stack);
}
