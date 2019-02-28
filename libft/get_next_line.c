/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:34:15 by jgabelho          #+#    #+#             */
/*   Updated: 2019/02/27 16:35:27 by jgabelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "includes/libft.h"

static int		ft_strchri(char *s1, char c)
{
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char		*strjoindel(char *s1, char *s2, int num)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (num == 0)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	if (num == 1)
	{
		ft_strdel(&s1);
	}
	if (num == 2)
	{
		ft_strdel(&s2);
	}
	return (ret);
}

static int		read_line(const int fd, char **overflow)
{
	char	*buf;
	int		i;

	buf = ft_strnew(BUFF_SIZE);
	if (!buf)
		return (-1);
	i = 0;
	while (!ft_strchr(*overflow, '\n') && (i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		*overflow = strjoindel(*overflow, buf, 1);
		ft_strclr(buf);
	}
	ft_strdel(&buf);
	if (i < BUFF_SIZE)
		return (0);
	return (1);
}

static int		get_line(char **line, char **overflow)
{
	int		i;

	i = ft_strchri(*overflow, '\n');
	if (i == -1)
	{
		*line = ft_strdup(*overflow);
		ft_strclr(*overflow);
		return (0);
	}
	*line = ft_strnew(i);
	ft_memcpy(*line, *overflow, i);
	ft_memmove(*overflow, *overflow + i + 1, ft_strlen(*overflow) - i);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*overflow[MAX_FD];
	int				reader;
	int				getter;

	if (fd < 0 || fd >= MAX_FD)
		return (-1);
	if (read(fd, overflow[0], 0) == -1)
		return (-1);
	if (line == NULL)
		return (-1);
	if (!overflow[fd])
	{
		overflow[fd] = ft_strnew(1);
		if (!overflow[fd] && !*line)
			return (-1);
	}
	reader = read_line(fd, &overflow[fd]);
	getter = get_line(line, &overflow[fd]);
	if (reader == 0 && getter == 0 && !**line)
	{
		ft_strdel(&overflow[fd]);
		return (0);
	}
	else
		return (1);
}
