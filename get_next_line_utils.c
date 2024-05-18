/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:25:13 by sishizaw          #+#    #+#             */
/*   Updated: 2024/05/18 15:34:16 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cpy(char *dest, char *src, int n)
{
	size_t	i;

	i = 0;
	while (src[i] && 0 < n)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	dest[i] = '\0';
	return (dest + i);
}

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	size_t		s1_len;
	size_t		s2_len;
	char		*result;

	s1_len = 0;
	s2_len = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (s1 != NULL)
		s1_len = ft_strlen(s1);
	if (s2 != NULL)
		s2_len = ft_strlen(s2);
	result = (char *)malloc(s1_len + n + 1);
	if (result == NULL)
		return (NULL);
	cpy(cpy(result, (char *)s1, s1_len), (char *)s2, n);
	free((char *)s1);
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

char	*ft_strchr_len(const char *str, int c)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;
	char	*ptr;

	len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	ptr = dest;
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

