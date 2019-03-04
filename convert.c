/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:24:57 by jgabelho          #+#    #+#             */
/*   Updated: 2019/03/03 18:25:14 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes/libft.h"

t_coor	**c_array(int **coor, int xmax, int ymax)
{
	int			x;
	int			y;
	t_coor		**c;

	c = malloc(sizeof(t_coor *) * ymax);
	y = 0;
	while (y < ymax)
	{
		x = 0;
		c[y] = malloc(sizeof(t_coor) * xmax);
		while (x < xmax)
		{
			c[y][x].x = WIDTH / xmax * 0.5 * (x - xmax / 2.0);
			c[y][x].y = HEIGHT / ymax * 0.5 * (y - ymax / 2.0);
			c[y][x].z = -10 * coor[y][x];
			x++;
		}
		y++;
	}
	return (c);
}
