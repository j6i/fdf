/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:49:10 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 15:45:54 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*fresh;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	len = ft_strlen((char *)s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	if (len - i < 0)
		return (ft_strnew(1));
	if ((fresh = (char *)malloc((len - i + 1) * sizeof(char))) == 0)
		return (0);
	while (i < len)
		fresh[j++] = s[i++];
	fresh[j] = '\0';
	return (fresh);
}
