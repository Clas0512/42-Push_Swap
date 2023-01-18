/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:16:01 by anargul           #+#    #+#             */
/*   Updated: 2023/01/16 20:38:54 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystacks, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (needle[0] == '\0')
		return ((char *)haystacks);
	while (haystacks[h] != '\0')
	{
		n = 0;
		while (haystacks[h + n] == needle[n] && (h + n) < len)
		{
			if (haystacks[h + n] == '\0' && needle[n] == '\0')
				return ((char *)&haystacks[h]);
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)haystacks + h);
		h++;
	}
	return (0);
}
