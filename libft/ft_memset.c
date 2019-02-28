/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:45:37 by jgabelho          #+#    #+#             */
/*   Updated: 2018/11/28 16:03:55 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	dest = str;
	i = 0;
	while (i < n)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
