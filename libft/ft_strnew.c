/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:33:07 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 15:32:31 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;

	s = (char *)malloc((size + 1) * sizeof(char));
	if (s == 0)
		return (0);
	ft_bzero(s, size + 1);
	return (s);
}
