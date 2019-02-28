/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:06:15 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/03 14:46:33 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*fresh;

	if (!s)
		return (0);
	fresh = ft_strnew(len);
	if (!fresh)
		return (0);
	fresh = ft_strncpy(fresh, (char *)s + start, len);
	return (fresh);
}
