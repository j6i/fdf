/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:31:55 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/09 13:56:06 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstget(t_list *lst, int n)
{
	int		i;

	if (!lst)
		return (0);
	if (n > ft_lstlen(lst))
		return (0);
	i = 0;
	while (i < n)
	{
		i++;
		lst = lst->next;
	}
	return (lst);
}
