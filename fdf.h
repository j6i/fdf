/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:32:32 by jgabelho          #+#    #+#             */
/*   Updated: 2019/03/03 18:55:20 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

#define PI 3.14159265359
#define WIDTH 1200
#define HEIGHT 1200

typedef struct		s_coor
{
	double			x;
	double			y;
	double			z;
}					t_coor;

typedef struct		s_map
{
	t_coor			**c;
	int				xmax;
	int				ymax;
}					t_map;

int					deal_key(int key, void *param);

double				find_increment(double *x, double *y, double dx, double dy);

void				draw_line(void *m_p, void *w_p, t_coor start, t_coor end);

void				print_map(void *m_p, void *w_p, t_map *m);

int					**file_reader(char	*file, int ymax);

int					**coords(int fd, char *file, int ymax);

int					*xyz(char *line);

int					file_width(char *file);

int					file_len(char *file);

t_coor				**c_array(int **coor, int xmax, int ymax);

void				rotate_z(t_coor **c, int xmax, int ymax, double theta);

void				rotate_y(t_coor **c, int xmax, int ymax, double theta);

void				rotate_x(t_coor **c, int xmax, int ymax, double theta);

void				rotate_iso(t_map *m);

void				rotate_cool(t_map *m);

#endif
