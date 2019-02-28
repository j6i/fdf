/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:50:56 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 15:32:13 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*fresh;
	unsigned int		i;

	i = 0;
	if (!s || !f)
		return (0);
	fresh = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (fresh == 0)
		return (0);
	while (s[i] != '\0')
	{
		fresh[i] = f(i, s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
