/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <stanislav@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:26:07 by stanislav         #+#    #+#             */
/*   Updated: 2021/10/25 23:26:08 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!(s1 && s2))
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (str)
	{
		ft_strlcpy(str, s1, len1 + 1);
		ft_strlcpy(str + len1, s2, len2 + 1);
		free((void *)s1);
	}
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	l;

	if (size)
	{
		l = 0;
		size -= 1;
		while (src[l] && (l < size))
		{
			dst[l] = src[l];
			l++;
		}
		dst[l] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	total;

	total = nmemb * size;
	if (!total)
		total = 1;
	mem = malloc(total);
	if (mem)
		ft_memset(mem, 0, total);
	return (mem);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ma;
	unsigned char	chr;

	ma = s;
	chr = c;
	while (n--)
		*ma++ = chr;
	return (s);
}
