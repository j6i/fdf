/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:14:52 by jgabelho          #+#    #+#             */
/*   Updated: 2018/11/29 12:20:16 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*nustr;
	int		i;

	i = 0;
	nustr = (char *)str;
	while (str[i] != '\0')
	{
		i++;
		nustr++;
	}
	while (i >= 0)
	{
		if (str[i] == c)
		{
			return (nustr);
		}
		i--;
		nustr--;
	}
	return (0);
}
