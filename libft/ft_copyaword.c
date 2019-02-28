/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyaword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:49:11 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 18:58:02 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copyaword(const char *s, char c)
{
	char		*frsh;
	int			i;
	int			len;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	frsh = ft_strnew(len);
	frsh = ft_strncpy(frsh, s, len);
	return (frsh);
}
