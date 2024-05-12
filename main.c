#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h" 

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
		printf("%s\n", line);
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

