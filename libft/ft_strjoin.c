/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:34:10 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 15:31:44 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	if ((fresh = ft_strnew(len1 + len2)) == 0)
		return (0);
	if (len1)
		fresh = ft_strcpy(fresh, s1);
	if (len2)
		fresh = ft_strcat(fresh, s2);
	fresh[len1 + len2] = '\0';
	return (fresh);
}
