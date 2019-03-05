/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:24:57 by jgabelho          #+#    #+#             */
/*   Updated: 2019/03/05 15:17:12 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/libft.h"

t_coor	**c_array(int **coor, int xmax, int ymax)
{
	int			x;
	int			y;
	t_coor		**c;

	if ((c = malloc(sizeof(t_coor *) * ymax)) == 0)
		return (0);
	y = 0;
	while (y < ymax)
	{
		x = 0;
		if ((c[y] = malloc(sizeof(t_coor) * xmax)) == 0)
		{
			write(1, "malloc failed", 13);
			return (0);
		}
		while (x < xmax)
		{
			c[y][x].x = 1200 / xmax * 0.5 * (x - xmax / 2.0);
			c[y][x].y = 1200 / ymax * 0.5 * (y - ymax / 2.0);
			c[y][x].z = -10 * coor[y][x];
			x++;
		}
		y++;
	}
	return (c);
}
