#include "get_next_line.h"


// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

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