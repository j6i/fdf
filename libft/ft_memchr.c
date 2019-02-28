/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:54:39 by jgabelho          #+#    #+#             */
/*   Updated: 2018/11/29 11:59:56 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char		*ptr;
	unsigned char		*ptr2;
	size_t				i;

	ptr = (unsigned char *)str;
	ptr2 = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == ptr2[i])
		{
			return (void *)(ptr);
		}
		ptr++;
		i++;
	}
	return (0);
}
