/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:06:48 by anargul           #+#    #+#             */
/*   Updated: 2023/01/18 19:46:48 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
	int	*each_arg_c;
}		t_stacks;

void	ft_index(t_stacks *stacks);
void	fake_sort(int *temp, t_stacks *stacks);
void	find_plcs(int *temp, t_stacks *stacks);
void	radix_sort(t_stacks *stacks);
void	ft_error(void);
void	ft_isthr_cpy(t_stacks *stackss);
void	ft_check_arg(int ac, char **argv, t_stacks *stackss);
void	ft_sa(t_stacks *stacks);
void	ft_sb(t_stacks *stacks);
void	ft_ss(t_stacks *stacks);
void	ft_pa(t_stacks *stacks);
void	ft_pb(t_stacks *stacks);
void	ft_rrb(t_stacks *stacks);
void	ft_rra(t_stacks *stacks);
void	ft_rrr(t_stacks *stacks);
void	ft_rb(t_stacks *stacks);
void	ft_ra(t_stacks *stacks);
void	ft_rr(t_stacks *stacks);
void	ft_set_stacks(t_stacks *stackss, int ac, char **av);
void	ft_sorting(t_stacks *stacks);
void	three_sort(t_stacks *stacks);
int		ft_is_sorted(t_stacks *stackss);

#endif