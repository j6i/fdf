/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:03:46 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/06 19:35:13 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		dstlen;
	size_t		srclen;

	i = 0;
	j = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen((char*)src);
	if (size < dstlen + 1)
		return (srclen + size);
	i = dstlen;
	while (i < size - 1 && src[j])
		dst[i++] = src[j++];
	if (src[j] == '\0')
	{
		dst[i] = 0;
		return (i);
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
