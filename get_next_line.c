/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:12:24 by sishizaw          #+#    #+#             */
/*   Updated: 2024/05/18 17:28:35 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void safe_free(char **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

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
				return (free(buf), -1);
			*st_arr = ft_strdup(temp + 1);
			if (!st_arr)
				return (free(buf), -1);
		}
		else
		{
			len = ft_strlen(buf);
			*line = ft_strnjoin(*line, buf, len);
			if (!line)
				return (free(buf), -1);
		}
		break;
	}
	free(buf);
	buf = NULL;
	if (bytes_read < 0)
		return (-1);
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
	if (line == NULL)
		return (NULL);
	if (st_arr[fd])
	{
		free(line);
		line = ft_strdup(st_arr[fd]);
		if (line == NULL)
			return (NULL);
		free(st_arr[fd]);
		st_arr[fd] = NULL;
	}
	ret = read_fd(fd, &line, &st_arr[fd]);
	printf("戻り値：%d\n", ret);
	if (ret < 0 || (ret == 0 && line[0] == '\0'))
	{
		safe_free(&st_arr[fd]);
		safe_free(&line);
		return (NULL);
	}
	return (line);
}

int	main()
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("faild to open file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	if (close(fd) == -1)
	{
		perror("failed to close file");
		return (1);
	}
	return (0);
}