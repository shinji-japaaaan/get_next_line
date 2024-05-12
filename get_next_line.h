#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef FD_MAX
#  define FD_MAX 256
# endif

char		*get_next_line(int fd);
static char	*cpy(char *dest, char *src, int n);
char		*ft_strnjoin(char const *s1, char const *s2, int n);
char	*ft_strchr_len(const char *str, int c, int bytes_read);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);

#endif
