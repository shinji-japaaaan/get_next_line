#include "get_next_line.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

int	main(void)
{
	int	fd;
	char	*str;
	// char	*str2;

	fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < 5; i++)
	{
	str = get_next_line(fd);
	// str2 = get_next_line(fd);
	printf("%s", str);	
	free(str);
	}
	close(fd);
	// printf("%s", str2);

	// fd = 0;
	// str = get_next_line(fd);
	// close(fd);
	// printf("%s", str);
	// free(str);

	// free(str);
	// free(str2);
}