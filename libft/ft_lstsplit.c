/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:27:35 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/12 12:47:50 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstsplit(const char *s, char c)
{
	char		**tab;
	t_list		*lst;
	int			i;

	if (!s || !c)
		return (0);
	if ((tab = ft_strsplit(s, c)) == 0)
		return (0);
	i = 0;
	if (!tab[i])
		return (0);
	lst = 0;
	while (i < ft_countword(s, c))
	{
		ft_lstadd(&lst, ft_lstnew(tab[i], ft_strlen(tab[i])));
		i++;
	}
	free(tab);
	return (lst);
}
