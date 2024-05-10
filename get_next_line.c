/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:48:53 by sishizaw          #+#    #+#             */
/*   Updated: 2024/05/10 11:38:18 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int find_newline(char *st_arr, char *buf)
{
	char *newline_pos;

	if ((newline_pos = ft_strchr_len(st_arr, '\n')) >= 0)
	{
		buf[newline_pos] = '\0';
		return 1;
	}
	return 0;
}

static int read_fd(int fd, char **st_arr)
{
	char *buf;
	ssize_t read_size;
	char *temp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (*st_arr)
		{
			temp = *st_arr;
			*st_arr = ft_strnjoin(*st_arr, buf, read_size);
			free(temp);
		}
		else
			*st_arr = ft_strdup(buf);
		if (find_newline(*st_arr, buf))
		{
			free(buf);
			return 1;
		}
	}
	free(buf);
	if (read_size < 0)
		return -1;
	return 0;
}

int get_next_line(int fd, char **line)
{
	static char *st_arr[OPEN_MAX];

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return -1;
	int ret = read_fd(fd, &st_arr[fd]);
	if (ret != 0 || st_arr[fd] == NULL || st_arr[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = ft_strdup("");
		return ret;
	}
	*line = st_arr[fd];
	st_arr[fd] = NULL;
	return 0;
}
