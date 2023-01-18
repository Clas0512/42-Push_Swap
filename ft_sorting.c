/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:32:58 by anargul           #+#    #+#             */
/*   Updated: 2023/01/16 20:58:15 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	extra(t_stacks *stacks)
{
	ft_pb(stacks);
	three_sort(stacks);
	ft_rrb(stacks);
	ft_pa(stacks);
	ft_ra(stacks);
}

void	three_sort(t_stacks *stacks)
{
	if (!ft_is_sorted(stacks))
		return ;
	if (stacks->a[0] > stacks->a[1] && stacks->a[0] > stacks->a[2])
	{
		ft_ra(stacks);
		if (stacks->a[1] < stacks->a[2] && stacks->a[1] < stacks->a[0])
			ft_sa(stacks);
	}
	else if (stacks->a[1] > stacks->a[0] && stacks->a[1] > stacks->a[2])
	{
		ft_rra(stacks);
		if (stacks->a[1] < stacks->a[2] && stacks->a[1] < stacks->a[0])
			ft_sa(stacks);
	}
	else
		ft_sa(stacks);
}

void	four_sort(t_stacks *stacks)
{
	if (stacks->a[0] == 3)
		extra(stacks);
	else if (stacks->a[1] == 3)
	{
		ft_sa(stacks);
		four_sort(stacks);
	}
	else if (stacks->a[2] == 3)
	{
		ft_rra(stacks);
		four_sort(stacks);
	}
	else
	{
		ft_rra(stacks);
		four_sort(stacks);
	}
}

void	lower_sort(t_stacks *stacks)
{
	while (2 <= stacks->a[0])
		ft_ra(stacks);
	if (2 > stacks->a[0])
		ft_pb(stacks);
	while (2 <= stacks->a[0])
		ft_ra(stacks);
	if (2 > stacks->a[0])
		ft_pb(stacks);
	three_sort(stacks);
	if (stacks->b[1] > stacks->b[0])
		ft_sb(stacks);
	ft_pa(stacks);
	ft_pa(stacks);
}

void	ft_sorting(t_stacks *stacks)
{
	int	size;

	size = stacks->a_size;
	if (size == 2)
		ft_sa(stacks);
	else if (size == 3)
		three_sort(stacks);
	else if (size == 4)
		four_sort(stacks);
	else if (size < 6)
		lower_sort(stacks);
	else
		radix_sort(stacks);
}
