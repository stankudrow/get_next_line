/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:08:39 by stanislav         #+#    #+#             */
/*   Updated: 2022/09/16 19:09:20 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	nbytes;
	char	*line;
	size_t	linesize;
	FILE	*stream;

	line = NULL;
	linesize = BUFFER_SIZE;
	stream = fdopen(fd, "r");
	if (stream == NULL)
		return (NULL);
	nbytes = ft_getline(&line, &linesize, stream);
	if (nbytes < 0)
		return (NULL);
	return (line);
}
