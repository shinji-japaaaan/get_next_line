/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:50:04 by sishizaw          #+#    #+#             */
/*   Updated: 2024/05/13 17:52:56 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// get_next_line_bonus.h

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
char		*ft_strchr_len(const char *str, int c, int bytes_read);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);

#endif
