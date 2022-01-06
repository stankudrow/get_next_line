/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <stanislav@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:26:24 by stanislav         #+#    #+#             */
/*   Updated: 2021/10/25 23:26:24 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4095
# endif

# if (BUFFER_SIZE) <= 0
#  error Invalid buffer of (BUFFER_SIZE) size
# endif

# define CACHE_SIZE 255

// bp/cp - current position in the buffer/cache arrays.
// nbs - number of bytes read from fd into the buffer.
typedef struct s_fdb
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	size_t			bp;
	char			cache[CACHE_SIZE + 1];
	size_t			cp;
	ssize_t			nbs;
	struct s_fdb	*next;
}	t_fdb;

char	*get_next_line(int fd);

char	*gnl_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);

#endif
