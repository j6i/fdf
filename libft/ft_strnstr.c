/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:25:42 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/06 19:06:00 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t		i;
	size_t		j;
	char		*hay;

	i = 0;
	j = 0;
	hay = (char *)big;
	if (ft_strlen((char*)lil) > ft_strlen((char*)big))
		return (0);
	if (lil[i] == '\0' || big[i] == '\0')
		return ((char*)big);
	while (i < len)
	{
		j = 0;
		while (hay[i + j] == lil[j] && i + j < len)
		{
			if (lil[j + 1] == '\0')
				return ((char *)big);
			j++;
		}
		big++;
		i++;
	}
	return (0);
}
