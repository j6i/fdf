/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:48:27 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 12:02:44 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	if (!alst || !*alst)
		return ;
	tmp = *alst;
	del(tmp->content, tmp->content_size);
	free(*alst);
	*alst = NULL;
}
