/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:48:53 by sishizaw          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_newline(int fd, char **line, char **st_arr, char *buf)
{
	char	len;
	int		bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (bytes_read);
	buf[bytes_read] = '\0';
	len = ft_strchr_len(buf, '\n', byted_read);
	if (len)
	{
		*line = ft_strnjoin(*line, buf, len);
		*st_arr = ft_strdup(buf[len] + 0);
		free(buf);
		return (1);
	}
	*line = ft_strnjoin(*line, buf, bytes_read);
	return (0);
}

static int	read_fd(int fd, char **line, char **st_arr)
{
	char	*buf;
	int		ret;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	ret = find_newline(fd, line, st_arr, buf);
	free(buf);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*st_arr[FD_MAX];
	char		*line;
	int			ret;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_stedup("");
	if(!line)
		rteturn (NULL);
	if (st_arr[fd]
	{
		line =ft_strdup(st_arr[fd];
		free(st_arr[fd]);
		st_arr[fd]) = NULL;
	}
	ret = read_fd(fd, &line, &st_arr[fd]);
	if (ret <= 0 && !ft_strlen(line))
	{
	free(line)
	line = NULL;
	}
	return (line);
