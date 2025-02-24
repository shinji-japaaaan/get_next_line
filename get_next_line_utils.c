/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:25:13 by sishizaw          #+#    #+#             */
/*   Updated: 2025/02/24 19:48:36 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	if (dest == NULL || src == NULL || n < 0)
		return (NULL); 

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	if (dest == NULL || src == NULL)  // NULLポインタチェック
		return (NULL);

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	size_t		s1_len;
	char		*result;
	size_t		i;
	size_t		j;

	if (s1 == NULL || s2 == NULL || n < 0)  // NULLポインタとnのチェック
		return (NULL);
	s1_len = ft_strlen(s1);
	result = (char *)malloc(s1_len + n + 1);  // 確保するメモリのサイズを正しく計算
	if (result == NULL)
		return (NULL);  // malloc失敗時にNULLを返す
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < n && s2[j] != '\0')  // nに制限を加える
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

	if (str == NULL)  // NULLポインタチェック
		return (NULL);

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

	if (src == NULL)  // NULLポインタチェック
		return (NULL);

	len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);  // malloc失敗時にNULLを返す

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

