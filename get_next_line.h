#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
static char	*cpy(char *dest, char *src, int n);
char		*ft_strnjoin(char const *s1, char const *s2, int n);
size_t		ft_strlen(const char *str);
char		ft_strchr(char *buf, int c, int bytes_read);
char		*ft_strdup(const char *src);

#endif
