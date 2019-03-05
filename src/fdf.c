/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:16:40 by jgabelho          #+#    #+#             */
/*   Updated: 2019/03/05 15:16:39 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/libft.h"

int		deal_key(int key, void *m)
{
	if (key == 53)
	{
		exit(0);
		return (0);
	}
	if (key == 34)
	{
		mlx_clear_window(((t_map *)m)->m_p, ((t_map *)m)->w_p);
		rotate_iso((t_map *)m);
		print_map(((t_map *)m)->m_p, ((t_map *)m)->w_p, (t_map *)m);
	}
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
		mlx_pixel_put(m_p, w_p, x + 600, y + 600, 0xaad7ff);
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
		x = 1;
		while (x < m->xmax)
		{
			draw_line(m_p, w_p, m->c[y][x - 1], m->c[y][x]);
			x++;
		}
		y++;
	}
	x = 0;
	while (x < m->xmax)
	{
		y = 1;
		while (y < m->ymax)
		{
			draw_line(m_p, w_p, m->c[y - 1][x], m->c[y][x]);
			y++;
		}
		x++;
	}
}

int		main(int argc, char **argv)
{
	int		**coor;
	t_map	*m;

	if (argc != 2)
		return (0);
	m = malloc(sizeof(t_map));
	if ((m->xmax = file_width(argv[1])) == 0)
		return (0);
	if ((m->ymax = file_len(argv[1])) == 0)
		return (0);
	m->m_p = mlx_init();
	m->w_p = mlx_new_window(m->m_p, 1200, 1200, "memes");
	if ((coor = file_reader(argv[1], m->xmax, m->ymax)) == 0)
		return (0);
	if ((m->c = c_array(coor, m->xmax, m->ymax)) == 0)
		return (0);
	if ((m->cog = c_array(coor, m->xmax, m->ymax)) == 0)
		return (0);
	rotate_cool(m);
	print_map(m->m_p, m->w_p, m);
	mlx_key_hook(m->w_p, deal_key, (void *)m);
	mlx_loop(m->m_p);
	return (0);
}
