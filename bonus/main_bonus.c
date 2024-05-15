// #include <fcntl.h>
// #include <stdio.h>
// #include "get_next_line_bonus.h"

// int main(void)
// {
// 	int fd1, fd2, fd3;
// 	char *line;

// 	fd1 = open("file1.txt", O_RDONLY);
// 	fd2 = open("file2.txt", O_RDONLY);
// 	fd3 = open("file3.txt", O_RDONLY);

// 	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}

// 	printf("Reading from file1.txt:\n");
// 	while ((line = get_next_line(fd1)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = NULL;
// 	}

// 	printf("Reading from file2.txt:\n");
// 	while ((line = get_next_line(fd2)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	printf("Reading from file3.txt:\n");
// 	while ((line = get_next_line(fd3)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);

// 	fd1 = open("file1.txt", O_RDONLY);
// 	fd2 = open("file2.txt", O_RDONLY);
// 	fd3 = open("file3.txt", O_RDONLY);

// 	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}

// 	printf("Reading from file1.txt again:\n");
// 	while ((line = get_next_line(fd1)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	printf("Reading from file2.txt again:\n");
// 	while ((line = get_next_line(fd2)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	printf("Reading from file3.txt again:\n");
// 	while ((line = get_next_line(fd3)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = NULL;
// 	}

// 	close(fd1);
// 	close(fd2);
// 	close(fd3);

// 	return (0);
// }
