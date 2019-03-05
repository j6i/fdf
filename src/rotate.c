/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:31:44 by jgabelho          #+#    #+#             */
/*   Updated: 2019/03/05 15:07:29 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/libft.h"

void	rotate_iso(t_map *m)
{
	double		thetay;
	double		thetaz;

	thetay = PI / 5.6;
	thetaz = 0.615472907;
	rotate_y(m, m->cog, m->c, thetay);
	rotate_z(m, m->c, m->c, thetaz);
}

void	rotate_cool(t_map *m)
{
	double		thetax;
	double		thetay;
	double		thetaz;

	thetax = PI / 4.0;
	thetay = PI / 6.0;
	thetaz = PI / 6.0;
	rotate_z(m, m->cog, m->c, thetaz);
	rotate_x(m, m->c, m->c, thetax);
	rotate_y(m, m->c, m->c, thetay);
}

void	rotate_x(t_map *m, t_coor **from, t_coor **result, double theta)
{
	int		x;
	int		y;

	y = 0;
	while (y < m->ymax)
	{
		x = 0;
		while (x < m->xmax)
		{
			result[y][x].x = from[y][x].x;
			result[y][x].y = from[y][x].y * cos(theta) +
				from[y][x].z * sin(theta);
			result[y][x].z = -from[y][x].y * sin(theta) +
				from[y][x].z * cos(theta);
			x++;
		}
		y++;
	}
}

void	rotate_y(t_map *m, t_coor **from, t_coor **result, double theta)
{
	int		x;
	int		y;

	y = 0;
	while (y < m->ymax)
	{
		x = 0;
		while (x < m->xmax)
		{
			result[y][x].x = from[y][x].x * cos(theta) +
				from[y][x].z * sin(theta);
			result[y][x].y = from[y][x].y;
			result[y][x].z = -from[y][x].x * sin(theta) +
				from[y][x].z * cos(theta);
			x++;
		}
		y++;
	}
}

void	rotate_z(t_map *m, t_coor **from, t_coor **result, double theta)
{
	int		x;
	int		y;

	y = 0;
	while (y < m->ymax)
	{
		x = 0;
		while (x < m->xmax)
		{
			result[y][x].x = from[y][x].x * cos(theta) -
				from[y][x].y * sin(theta);
			result[y][x].y = from[y][x].x * sin(theta) +
				from[y][x].y * cos(theta);
			result[y][x].z = from[y][x].z;
			x++;
		}
		y++;
	}
}
