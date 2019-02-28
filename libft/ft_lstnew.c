/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:08:58 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 15:28:37 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*fresh;

	if ((fresh = (t_list *)malloc(sizeof(t_list) * (content_size))) == 0)
		return (0);
	if (content == NULL)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		if ((fresh->content = malloc(content_size)) == 0)
			return (0);
		ft_memcpy(fresh->content, content, content_size);
		fresh->content_size = content_size;
		fresh->next = 0;
	}
	return (fresh);
}
