/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:22:13 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 15:49:51 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	char	*p;
	int		i;
	int		j;

	if (!s || !c)
		return (0);
	if ((fresh = malloc((ft_countword(s, c) + 1) * sizeof(char *))) == 0)
		return (0);
	i = 0;
	j = 0;
	p = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			fresh[j++] = ft_copyaword(p, c);
			while (s[i + 1] != c && s[++i + 1] != '\0')
				p++;
		}
		i++;
		p++;
	}
	fresh[j] = 0;
	return (fresh);
}
