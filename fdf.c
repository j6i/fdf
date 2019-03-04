/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:16:40 by jgabelho          #+#    #+#             */
/*   Updated: 2019/03/03 18:56:22 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes/libft.h"

int		deal_key(int key, void *param)
{
	exit(0);
	return (0);
}

double	find_increment(double *x, double *y, double dx, double dy)
{
	double	step;

	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	*x = dx / step;
	*y = dy / step;
	return (step);
}

void	draw_line(void *m_p, void *w_p, t_coor start, t_coor end)
{
	double xi;
	double yi;
	double x;
	double y;
	double step;

	step = find_increment(&xi, &yi, end.x - start.x, end.y - start.y);
	x = start.x;
	y = start.y;
	while (step >= 0)
	{
		mlx_pixel_put(m_p, w_p, x + 600, y + 600, 0xFF00FF);
		x += xi;
		y += yi;
		step--;
	}
}

void	print_map(void *m_p, void *w_p, t_map *m)
{
	int		x;
	int		y;

	y = 0;
	while (y < m->ymax)
	{
		x = 0;
		while (x < m->xmax - 1)
		{
			draw_line(m_p, w_p, m->c[y][x], m->c[y][x + 1]);
			x++;
		}
		y++;
	}
	x = 0;
	while (x < m->xmax)
	{
		y = 0;
		while (y < m->ymax - 1)
		{
			draw_line(m_p, w_p, m->c[y][x], m->c[y + 1][x]);
			y++;
		}
		x++;
	}
}

int		main(int argc, char **argv)
{
	void	*m_p;
	void	*w_p;
	int		**coor;
	t_map	*m;

	m = malloc(sizeof(t_map *));
	m->xmax = file_width(argv[1]);
	m->ymax = file_len(argv[1]);
	m_p = mlx_init();
	w_p = mlx_new_window(m_p, WIDTH, HEIGHT, "memes");
	coor = file_reader(argv[1], m->ymax);
	m->c = c_array(coor, m->xmax, m->ymax);
	rotate_cool(m);
	print_map(m_p, w_p, m);
	mlx_key_hook(w_p, deal_key, (void *)0);
	mlx_loop(m_p);
	return (0);
}
