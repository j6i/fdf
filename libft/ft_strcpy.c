/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:43:18 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/01 18:39:51 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strcpy(char *dest, const char *src)
{
	size_t		i;

	i = 0;
	while ((dest[i] = src[i]))
		i++;
	return (dest);
}
