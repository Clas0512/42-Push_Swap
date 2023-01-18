/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:32:52 by anargul           #+#    #+#             */
/*   Updated: 2023/01/16 20:39:55 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_of_num(char *str, t_stacks *stacks, int ac)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			result++;
		i++;
	}
	stacks->each_arg_c[ac] = result;
	return (result);
}

void	ft_general_check(char *str)
{
	int		i;
	char	c;
	int		s;

	s = 0;
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c != ' ' && c != '-' && !('0' <= c && c <= '9'))
			ft_error();
		if ((c == '-' && !('0' <= str[i + 1] && str[i + 1] <= '9'))
			|| (i > 0 && c == '-' && !(str[i - 1] == ' ')))
			ft_error();
		if ('0' <= c && c <= '9')
			s++;
		i++;
	}
	if (s == 0)
		ft_error();
}

void	ft_isthr_cpy(t_stacks *stacks)
{
	int	p;
	int	i;
	int	j;
	int	numc;

	i = 0;
	while (i < stacks->a_size)
	{
		p = stacks->a[i];
		j = 0;
		numc = 0;
		while (j < stacks->a_size)
		{
			if (p == stacks->a[j])
				numc++;
			if (numc > 1)
				ft_error();
			j++;
		}
		i++;
	}
}

void	ft_check_arg(int ac, char **argv, t_stacks *stacks)
{
	int	i;
	int	num_c;

	stacks->each_arg_c = malloc(sizeof(int) * ac);
	num_c = 0;
	i = 1;
	while (i < ac)
	{
		if (!*argv[i])
			exit(1);
		ft_general_check(argv[i]);
		num_c += ft_count_of_num(argv[i], stacks, i);
		i++;
	}
	if (num_c == 0)
		ft_error();
	stacks->a = malloc(sizeof(int) * num_c);
	if (!stacks->a)
		ft_error();
	stacks->b = malloc(sizeof(int) * num_c);
	if (!stacks->b)
		ft_error();
	stacks->a_size = num_c;
	stacks->b_size = 0;
}
