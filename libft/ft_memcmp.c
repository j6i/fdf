/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:37:20 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/02 15:42:57 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*c1;
	const unsigned char		*c2;
	size_t					i;

	c1 = (const unsigned char *)s1;
	c2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (c2[i] == c1[i])
			i++;
		else
			return (c1[i] - c2[i]);
	}
	return (0);
}
