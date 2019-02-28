/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:52:33 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/11 19:38:30 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*fresh;

	fresh = malloc(size * sizeof(*fresh));
	if (fresh == 0)
		return (0);
	ft_bzero(fresh, size);
	return ((void*)fresh);
}
