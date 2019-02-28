/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:54:43 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/06 19:12:51 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (ft_strcmp(s1, s2) == 0)
			return (1);
	}
	return (0);
}
