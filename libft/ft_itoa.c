/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:54:07 by jgabelho          #+#    #+#             */
/*   Updated: 2018/12/08 15:27:54 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(int n)
{
	char		*fresh;

	if ((fresh = (char *)malloc(sizeof(char) * 2)) == 0)
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(fresh, "-2147483648"));
	if (n < 0)
	{
		fresh[0] = '-';
		fresh[1] = '\0';
		fresh = ft_strjoin(fresh, ft_itoa(-n));
	}
	else if (n >= 10)
		fresh = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		fresh[0] = n + '0';
		fresh[1] = '\0';
	}
	return (fresh);
}
