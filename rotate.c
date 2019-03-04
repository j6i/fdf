/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:31:44 by jgabelho          #+#    #+#             */
/*   Updated: 2019/03/03 18:25:17 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes/libft.h"

void	rotate_iso(t_map *m)
{
	double		thetay;
	double		thetaz;

	thetay = 0.615472907;
	thetaz = 0.78539816339;
	rotate_y(m->c, m->xmax, m->ymax, thetay);
	rotate_z(m->c, m->xmax, m->ymax, thetaz);
}

void	rotate_cool(t_map *m)
{
	double		thetax;
	double		thetay;
	double		thetaz;

	thetax = PI / 10.0;
	thetay = PI / 10.0;
	thetaz = PI / 8.0;
	rotate_x(m->c, m->xmax, m->ymax, thetax);
	rotate_z(m->c, m->xmax, m->ymax, thetaz);
	rotate_y(m->c, m->xmax, m->ymax, thetay);
}

void	rotate_x(t_coor **c, int xmax, int ymax, double theta)
{
	int		x;
	int		y;

	y = 0;
	while (y < ymax)
	{
		x = 0;
		while (x < xmax)
		{
			c[y][x].y = c[y][x].y * cos(theta) + c[y][x].z * sin(theta);
			c[y][x].z = -c[y][x].y * sin(theta) + c[y][x].z * cos(theta);
			x++;
		}
		y++;
	}
}

void	rotate_y(t_coor **c, int xmax, int ymax, double theta)
{
	int		x;
	int		y;

	y = 0;
	while (y < ymax)
	{
		x = 0;
		while (x < xmax)
		{
			c[y][x].x = c[y][x].x * cos(theta) + c[y][x].z * sin(theta);
			c[y][x].z = -c[y][x].x * sin(theta) + c[y][x].z * cos(theta);
			x++;
		}
		y++;
	}
}

void	rotate_z(t_coor **c, int xmax, int ymax, double theta)
{
	int		x;
	int		y;

	y = 0;
	while (y < ymax)
	{
		x = 0;
		while (x < xmax)
		{
			c[y][x].x = c[y][x].x * cos(theta) - c[y][x].y * sin(theta);
			c[y][x].y = c[y][x].x * sin(theta) + c[y][x].y * cos(theta);
			x++;
		}
		y++;
	}
}
