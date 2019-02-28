/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:32:32 by jgabelho          #+#    #+#             */
/*   Updated: 2019/02/28 14:49:53 by jgabelho         ###   ########.fr       */
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

int					deal_key(int key, void *param);

void				plot_low(void *m_p, void *w_p, int **coor);

void				plot_high(void *m_p, void *w_p, int **coor);

void				plot_line(void *m_p, void *w_p, int **coor);

int					**file_reader(char	*file);

int					**coords(int fd);

int					*xyz(char *line, int *c);

#endif
