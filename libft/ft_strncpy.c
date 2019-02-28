/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:52:51 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/02 14:06:16 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t			slen;

	slen = ft_strlen((char *)src);
	ft_memcpy(dest, src, n);
	if (slen < n)
		while (slen < n)
		{
			dest[slen] = 0;
			slen++;
		}
	return (dest);
}
