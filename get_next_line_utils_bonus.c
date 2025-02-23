/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:25:13 by sishizaw          #+#    #+#             */
/*   Updated: 2024/05/19 11:56:26 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = dest;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += (n - 1);
		s += (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	size_t		s1_len;
	char		*result;
	size_t		i;
	size_t		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	result = (char *)malloc(s1_len + n + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i++] = s2[j++];
	}
	result[i] = '\0';
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
