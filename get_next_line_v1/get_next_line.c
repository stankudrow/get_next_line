/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <stanislav@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:26:00 by stanislav         #+#    #+#             */
/*   Updated: 2021/10/25 23:26:01 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static bool	gnl_get_line(t_fdb *fdb, char **line)
{
	while (*line && fdb->nbs > 0)
	{
		ft_memset(fdb->cache, 0, CACHE_SIZE);
		fdb->cp = 0;
		while ((fdb->cp < CACHE_SIZE) && fdb->nbs > 0)
		{
			if (fdb->buf[fdb->bp] == '\0')
			{
				fdb->nbs = read(fdb->fd, fdb->buf, BUFFER_SIZE);
				fdb->buf[fdb->nbs] = '\0';
				fdb->bp = 0;
			}
			fdb->cache[fdb->cp++] = fdb->buf[fdb->bp++];
			if (fdb->cache[fdb->cp - 1] == '\n')
				break ;
		}
		fdb->cache[fdb->cp] = '\0';
		*line = gnl_strjoin(*line, fdb->cache);
		if (fdb->cache[fdb->cp - 1] == '\n')
			return (true);
	}
	if (*line && **line)
		return (true);
	return (false);
}

static void	gnl_detach_fdb(int fd, t_fdb **fdblst)
{
	t_fdb	*curr_fdb;
	t_fdb	*prev_fdb;

	prev_fdb = NULL;
	curr_fdb = *fdblst;
	while (curr_fdb)
	{
		if (curr_fdb->fd == fd)
		{
			if (prev_fdb)
				prev_fdb->next = curr_fdb->next;
			else
				*fdblst = curr_fdb->next;
			free((void *)curr_fdb);
			return ;
		}
		prev_fdb = curr_fdb;
		curr_fdb = curr_fdb->next;
	}
}

static t_fdb	*gnl_init_fdb(int fd)
{
	t_fdb	*new_fdb;

	new_fdb = (t_fdb *)malloc(sizeof(t_fdb));
	if (!new_fdb)
		return (NULL);
	new_fdb->fd = fd;
	new_fdb->nbs = read(new_fdb->fd, new_fdb->buf, BUFFER_SIZE);
	if (new_fdb->nbs > 0)
	{
		new_fdb->buf[new_fdb->nbs] = '\0';
		new_fdb->bp = 0;
		ft_memset(new_fdb->cache, 0, CACHE_SIZE + 1);
		new_fdb->cp = 0;
		new_fdb->next = NULL;
		return (new_fdb);
	}
	free((void *)new_fdb);
	return (NULL);
}

static t_fdb	*gnl_get_fdb(int fd, t_fdb **fdblst)
{
	t_fdb	*last_fdb;
	t_fdb	*new_fdb;

	last_fdb = *fdblst;
	while (last_fdb)
	{
		if (last_fdb->fd == fd)
			return (last_fdb);
		if (!last_fdb->next)
			break ;
		last_fdb = last_fdb->next;
	}
	new_fdb = gnl_init_fdb(fd);
	if (!new_fdb)
		return (NULL);
	if (last_fdb)
		last_fdb->next = new_fdb;
	else
		*fdblst = new_fdb;
	return (new_fdb);
}

char	*get_next_line(int fd)
{
	static t_fdb	*fdblst = NULL;
	t_fdb			*fdb;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fdb = gnl_get_fdb(fd, &fdblst);
	if (!fdb)
		return (NULL);
	line = ft_calloc(1, sizeof(char));
	if (line)
	{
		if (gnl_get_line(fdb, &line))
			return (line);
		free((void *)line);
	}
	gnl_detach_fdb(fd, &fdblst);
	return (NULL);
}
