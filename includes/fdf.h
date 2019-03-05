/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:32:32 by jgabelho          #+#    #+#             */
/*   Updated: 2019/03/05 15:03:04 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define PI 3.14159265359
# define WIDTH 1200
# define HEIGHT 1200

typedef struct		s_coor
{
	double			x;
	double			y;
	double			z;
}					t_coor;

typedef struct		s_map
{
	t_coor			**c;
	t_coor			**cog;
	int				xmax;
	int				ymax;
	void			*m_p;
	void			*w_p;
}					t_map;

int					deal_key(int key, void *m);

double				find_increment(double *x, double *y, double dx, double dy);

void				draw_line(void *m_p, void *w_p, t_coor start, t_coor end);

void				print_map(void *m_p, void *w_p, t_map *m);

int					**file_reader(char	*file, int xmax, int ymax);

int					**coords(int fd, int xmax, int ymax);

int					*xyz(char *line, int xmax);

int					file_width(char *file);

int					file_len(char *file);

t_coor				**c_array(int **coor, int xmax, int ymax);

void				rotate_z(t_map *m, t_coor **from,
						t_coor **result, double theta);

void				rotate_y(t_map *m, t_coor **from,
						t_coor **result, double theta);

void				rotate_x(t_map *m, t_coor **from,
						t_coor **result, double theta);

void				rotate_iso(t_map *m);

void				rotate_cool(t_map *m);

#endif
