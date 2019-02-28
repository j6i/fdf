/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:33:00 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/06 19:48:34 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*odst;
	unsigned char		*osrc;
	size_t				i;

	odst = (unsigned char *)dest;
	osrc = (unsigned char *)src;
	i = 0;
	if (src < dest)
		while (n--)
			odst[n] = osrc[n];
	else
	{
		while (i < n)
		{
			odst[i] = osrc[i];
			i++;
		}
	}
	return (odst);
}
