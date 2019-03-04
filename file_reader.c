/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:55:08 by jgabelho          #+#    #+#             */
/*   Updated: 2019/03/03 18:20:48 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "includes/libft.h"

int		file_len(char *file)
{
	int		i;
	int		fd;
	char	*lines;

	i = 0;
	fd = open(file, O_RDONLY);
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
	fd = open(file, O_RDONLY);
	get_next_line(fd, &lines);
	close(fd);
	split = ft_strsplit(lines, ' ');
	while (split[i] != 0)
	{
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
	ft_strdel(&lines);
	return (i);
}

int		*xyz(char *line)
{
	char	**split;
	int		*z;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i] != 0)
		i++;
	z = malloc(sizeof(int) * i);
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

int		**coords(int fd, char *file, int ymax)
{
	int		**co;
	char	*lines;
	int		i;

	co = malloc(sizeof(int *) * ymax);
	i = 0;
	while (get_next_line(fd, &lines))
	{
		co[i] = xyz(lines);
		free(lines);
		i++;
	}
	ft_strdel(&lines);
	return (co);
}

int		**file_reader(char *file, int ymax)
{
	int		fd;
	int		**c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "open failed", 11);
		return (NULL);
	}
	c = coords(fd, file, ymax);
	close(fd);
	return (c);
}
