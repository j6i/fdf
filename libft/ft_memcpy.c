/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:03:46 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/06 19:46:18 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*s11;
	unsigned char		*s22;
	size_t				i;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	if (n == 0 || s1 == s2)
		return (s1);
	while (i < n)
	{
		s11[i] = s22[i];
		i++;
	}
	*s11 = *s22;
	return (s1);
}
