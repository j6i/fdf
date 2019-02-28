/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:43:50 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 19:04:48 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countword(const char *s, char c)
{
	int		count;
	char	*p;
	int		i;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	p = (char *)s;
	if (s[i] == 0 || !c)
		return (0);
	if (p[0] != c)
		count++;
	while (p[i] != 0)
	{
		if (p[i - 1] != c && p[i] == c)
			count++;
		i++;
	}
	if (p[i - 1] == c)
		count--;
	return (count);
}
