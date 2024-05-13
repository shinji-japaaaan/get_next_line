/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:48:53 by sishizaw          #+#    #+#             */
/*   Updated: 2024/05/13 17:53:43 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_newline(int fd, char **line, char **st_arr, char *buf)
{
	char	*temp;
	int		bytes_read;

	while (1)
	{
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (bytes_read);
	buf[bytes_read] = '\0';
	temp = ft_strchr_len(buf, '\n', bytes_read);
	if (temp)
	{
		*temp = '\0';
		*line = ft_strnjoin(*line, buf, temp - buf);
		*st_arr = ft_strdup(temp + 1);
		free(buf);
		return (1);
	}
	*line = ft_strnjoin(*line, buf, bytes_read);
	}
	free(buf);
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
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*st_arr[FD_MAX];
	char		*line;
	int			ret;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if(!line)
		return (NULL);
	if (st_arr[fd])
	{
		line =ft_strdup(st_arr[fd]);
		free(st_arr[fd]);
		st_arr[fd] = NULL;
	}
	ret = read_fd(fd, &line, &st_arr[fd]);
	if (ret <= 0 && !ft_strlen(line))
	{
	free(line);
	line = NULL;
	}
	return (line);
}
