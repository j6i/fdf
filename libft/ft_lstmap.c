/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:08:32 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 15:11:26 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*fresh;
	t_list		*tmp;

	if (!lst)
		return (0);
	tmp = f(lst);
	fresh = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(lst)))
		{
			free(tmp);
			return (0);
		}
		tmp = tmp->next;
	}
	return (fresh);
}
