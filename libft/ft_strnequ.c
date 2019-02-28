/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:02:04 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/03 13:03:46 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}
