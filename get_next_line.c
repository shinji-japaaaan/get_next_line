/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:48:53 by sishizaw          #+#    #+#             */
/*   Updated: 2024/05/15 17:07:14 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	find_newline(int fd, char **line, char **st_arr, char *buf)
{
	char	*temp;
	int		bytes_read;
	int		len;

	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		temp = ft_strchr_len(buf, '\n');
		if (temp)
		{
			len = temp - buf + 1;
			*line = ft_strnjoin(*line, buf, len);
			if (!line)
				return (-1);
			*st_arr = ft_strdup(temp + 1);
			if (!st_arr)
				return (free(st_arr), -1);
			break;
		}
		else
		{
			len = ft_strlen(buf);
			*line = ft_strnjoin(*line, buf, len);
		}
	}
	free(buf);
	buf = NULL;
	if (bytes_read < 0)
		return (-1);
	return (0);
}

static char	read_fd(int fd, char **line, char **st_arr)
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
	if (line == NULL)
		return (NULL);
	if (st_arr[fd])
	{
		free(line);
		line = ft_strdup(st_arr[fd]);
		printf("line: %s\n", line);
		if (line == NULL)
			return (NULL);
		free(st_arr[fd]);
		st_arr[fd] = NULL;
	}
	ret = read_fd(fd, &line, &st_arr[fd]);
	if (ret < 0)
		return (NULL);
	return (line);
}

