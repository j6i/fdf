/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:44:06 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/02 14:24:18 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		dlen;
	size_t		slen;
	size_t		i;

	dlen = ft_strlen(dest);
	slen = ft_strlen((char*)src);
	i = 0;
	if (slen < n)
		n = slen;
	while (i < n)
	{
		dest[dlen] = src[i];
		dlen++;
		i++;
	}
	dest[dlen] = '\0';
	return (dest);
}
