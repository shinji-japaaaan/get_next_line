/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:12:24 by sishizaw          #+#    #+#             */
/*   Updated: 2025/02/24 21:56:50 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "get_next_line_utils.c"

static void	safe_free(char **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*find_newline(char **st_arr)
{
	char	*newline_pos;
	char	*line;
	int		len;

	newline_pos = ft_strchr_len(*st_arr, '\n');
	if (newline_pos)
		len = newline_pos - *st_arr + 1;
	else
		len = ft_strlen(*st_arr);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_strncpy(line, *st_arr, len);
	line[len] = '\0';
	if (newline_pos)
		ft_strcpy(*st_arr, newline_pos + 1);
	else
		safe_free(st_arr);
	return (line);
}

static int	append_buffer(char **st_arr, char *buf, int count_bytes)
{
	char	*tmp;

	buf[count_bytes] = '\0';
	tmp = *st_arr;
	*st_arr = ft_strnjoin(*st_arr, buf, count_bytes);
	if (!*st_arr)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (0);
}

static int	read_fd(int fd, char **st_arr)
{
	char	*buf;
	int		count_bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	while (1)
	{
		count_bytes = read(fd, buf, BUFFER_SIZE);
		if (count_bytes <= 0 || append_buffer(st_arr, buf, count_bytes) < 0)
			break ;
		if (ft_strchr_len(*st_arr, '\n'))
			break ;
	}
	free(buf);
	if (count_bytes < 0)
		return (-1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*st_arr[FD_MAX];
	char		*line;
	int			ret;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (st_arr[fd] == NULL && (st_arr[fd] = ft_strdup("")) == NULL)
		return (NULL);
	ret = read_fd(fd, &st_arr[fd]);
	if (ret < 0 || (ret == 0 && *st_arr[fd] == '\0'))
	{
		safe_free(&st_arr[fd]);
		return (NULL);
	}
	line = find_newline(&st_arr[fd]);
	if (line == NULL)
		safe_free(&st_arr[fd]);
	return (line);
}


// int	main()
// {
// 	int	fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("faild to open file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	if (close(fd) == -1)
// 	{
// 		perror("failed to close file");
// 		return (1);
// 	}
// 	return (0);
// }
