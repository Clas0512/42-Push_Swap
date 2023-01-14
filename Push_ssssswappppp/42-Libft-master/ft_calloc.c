/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:49:34 by anargul           #+#    #+#             */
/*   Updated: 2022/07/01 22:50:53 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbyte, size_t size)
{
	void	*dst;

	dst = malloc(size * nbyte);
	if (!dst)
		return (0);
	ft_memset(dst, 0, size * nbyte);
	return (dst);
}
