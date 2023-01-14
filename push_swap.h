/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:06:48 by anargul           #+#    #+#             */
/*   Updated: 2023/01/15 00:34:27 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	a_size;
	int	b_size;
	int	*each_arg_c;
	int	*sign;
	int	sign_size;
}t_stack;

void	radix_sort(t_stack *stack);
void	five_sort_extra(t_stack *stack);
void	extra(t_stack *stack);
void	ft_error(void);
void	ft_isthr_cpy(t_stack *stacks);
void	ft_check_arg(int ac, char **argv, t_stack *stacks);
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_pa(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrr(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_set_stack(t_stack *stacks, int ac, char **av);
void	ft_sorting(t_stack *stack);
void	three_sort(t_stack *stack);
int		ft_is_sorted(t_stack *stacks);

#endif