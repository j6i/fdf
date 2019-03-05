/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:55:08 by jgabelho          #+#    #+#             */
/*   Updated: 2019/03/05 15:32:54 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/libft.h"
#include <errno.h>

int		file_len(char *file)
{
	int		i;
	int		fd;
	char	*lines;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		write(1, "open failed", 11);
		return (0);
	}
	while (get_next_line(fd, &lines))
	{
		free(lines);
		i++;
	}
	close(fd);
	ft_strdel(&lines);
	return (i);
}

int		file_width(char *file)
{
	int		fd;
	char	*lines;
	char	**split;
	int		i;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		write(1, "open failed", 11);
		return (0);
	}
	if (get_next_line(fd, &lines) == -1)
	{
		perror("fdf");
		exit(0);
	}
	close(fd);
	split = ft_strsplit(lines, ' ');
	while (split[i] != 0)
		ft_strdel(&split[i++]);
	free(split);
	ft_strdel(&lines);
	return (i);
}

int		*xyz(char *line, int xmax)
{
	char	**split;
	int		*z;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	if ((z = malloc(sizeof(int) * xmax)) == 0)
	{
		write(1, "malloc failed", 13);
		return (0);
	}
	i = 0;
	while (split[i] != 0)
	{
		z[i] = ft_atoi(split[i]);
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
	return (z);
}

int		**coords(int fd, int xmax, int ymax)
{
	int		**co;
	char	*lines;
	int		i;

	if ((co = malloc(sizeof(int *) * ymax)) == 0)
	{
		write(1, "malloc failed", 13);
		return (0);
	}
	i = 0;
	while (get_next_line(fd, &lines))
	{
		co[i] = xyz(lines, xmax);
		free(lines);
		i++;
	}
	ft_strdel(&lines);
	return (co);
}

int		**file_reader(char *file, int xmax, int ymax)
{
	int		fd;
	int		**c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "open failed", 11);
		return (NULL);
	}
	c = coords(fd, xmax, ymax);
	close(fd);
	return (c);
}
