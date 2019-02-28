/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:48:31 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 15:30:38 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*nustr;
	int		i;

	i = 0;
	nustr = (char *)str;
	if (str[i] == c)
		return (nustr);
	while (str[i] != '\0')
	{
		i++;
		nustr++;
		if (str[i] == c)
		{
			return (nustr);
		}
	}
	return (0);
}
