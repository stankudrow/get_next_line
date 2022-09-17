/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdelim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorton <mhorton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:14:12 by stanislav         #+#    #+#             */
/*   Updated: 2022/09/17 16:31:40 by mhorton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getline.h"

/*
$ man 3 getdelim

https://opensource.apple.com/source/file/file-54/file/src/getline.c.auto.html
*/

static int	validate_args(char **line, size_t *linesize, FILE *stream)
{
	if (line == NULL || linesize == NULL || stream == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	if (*line == NULL || *linesize == 0)
	{
		if (*linesize == 0)
			*linesize = BUFFER_SIZE;
		*line = malloc(*linesize);
		if (*line == NULL)
		{
			errno = ENOMEM;
			return (-1);
		}
	}
	return (0);
}

static int	realloc_line(char **line, size_t *linesize, char **pos, char **eob)
{
	char	*tmpbuf;
	size_t	new_size;
	size_t	pos_loc;

	if (*pos + 1 == *eob)
	{
		pos_loc = *pos - *line;
		new_size = *linesize * 2;
		tmpbuf = realloc(*line, new_size);
		if (tmpbuf == NULL)
			return (-1);
		*line = tmpbuf;
		*linesize = new_size;
		*pos = *line + pos_loc;
		*eob = *line + new_size;
	}
	return (0);
}

ssize_t	ft_getdelim(char **line, size_t *linesize, int delim, FILE *stream)
{
	char	*current;
	char	*block_end;
	int		chr;

	if (validate_args(line, linesize, stream))
		return (-1);
	current = *line;
	block_end = *line + *linesize;
	while (1)
	{
		if (realloc_line(line, linesize, &current, &block_end) < 0)
			return (-1);
		chr = fgetc(stream);
		if ((chr < 0) || (chr == delim))
		{
			*current = '\0';
			if (feof(stream) || (chr == delim))
				return (current - *line);
			return (errno);
		}
		*current++ = chr;
	}
}
