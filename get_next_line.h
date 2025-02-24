/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:22:39 by sishizaw          #+#    #+#             */
/*   Updated: 2025/02/24 18:27:48 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 4096
# endif

char		*get_next_line(int fd);
char		*ft_strnjoin(char const *s1, char const *s2, int n);
char		*ft_strchr_len(const char *str, int c);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char	    *ft_strcpy(char *dest, const char *src);
char	    *ft_strncpy(char *dest, const char *src, int n);

#endif
