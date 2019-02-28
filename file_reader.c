/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:55:08 by jgabelho          #+#    #+#             */
/*   Updated: 2019/02/27 20:02:37 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*xyz(char *line, int *c)
{

}

int		**coords(int fd)
{

}

int		**file_reader(char	*file)
{
	int		fd;
	int		**c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "open failed", 11);
		return (NULL);
	}
	c = coords(fd);
	if (close(fd) == -1)
	{
		write(1, "close failed", 12);
		return (NULL);
	}
	return (c);
}
