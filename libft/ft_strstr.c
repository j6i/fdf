/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:22:05 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 18:58:42 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*hay;

	i = 0;
	j = 0;
	hay = (char *)haystack;
	if (ft_strlen((char*)needle) > ft_strlen((char*)haystack))
		return (0);
	if (needle[i] == '\0' || haystack[i] == '\0')
		return ((char*)haystack);
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack);
			j++;
		}
		haystack++;
		i++;
	}
	return (0);
}
