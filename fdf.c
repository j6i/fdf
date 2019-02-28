/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:16:40 by jgabelho          #+#    #+#             */
/*   Updated: 2019/02/27 19:33:08 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes/libft.h"


int		deal_key(int key, void *param)
{
	exit(0);
	return (0);
}
/*
void	plot_low(void *m_p, void *w_p, t_list *coor)
{
	float		dx;
	float		dy;
	float		yi;
	float		d;
	float		y;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	y = y0;
	while (++x0 <= x1)
	{
		mlx_pixel_put(m_p, w_p, x0, y, 0xFFFFFF);
		if (d > 0)
		{
			y = y + yi;
			d = d - 2 * dx;
		}
		d = d + 2 * dy;
	}
}

void	plot_high(void *m_p, void *w_p, t_list *coor)
{
	float		dx;
	float		dy;
	float		xi;
	float		d;
	float		x;

	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	x = x0;
	while (++y0 <= y1)
	{
		mlx_pixel_put(m_p, w_p, x, y0, 0xFFFFFF);
		if (d > 0)
		{
			x = x + xi;
			d = d - 2 * dy;
		}
		d = d + 2 * dx;
	}
}

void	plot_line(void *m_p, void *w_p, t_list *coor)
{
	float		dx;
	float		dy;

	dx = x1 - x0;
	dy = y1 - y0;
	if (fabsf(dy) < fabsf(dx))
	{
		if (x1 > x0)
			plot_low(m_p, w_p, x1, y1, x0, y0);
		else
			plot_low(m_p, w_p, x0, y0, x1, y1);
	}
	else
	{
		if (y0 > y1)
			plot_high(m_p, w_p, x1, y1, x0, y0);
		else
			plot_high(m_p, w_p, x0, y0, x1, y1);
	}
}
*/
int		main(int argc, char **argv)
{

	void	*m_p;
	void	*w_p;
	int		**coor;

	m_p = mlx_init();
	w_p = mlx_new_window(m_p, 1000, 1000, "memes");
	coor = file_reader(argv[1]);
	//plot_line(m_p, w_p, coor);
	mlx_key_hook(w_p, deal_key, (void*)0);
	mlx_loop(m_p);

	return (0);
}
