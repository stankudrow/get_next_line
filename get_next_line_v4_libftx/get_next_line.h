/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:11:58 by stanislav         #+#    #+#             */
/*   Updated: 2022/09/16 19:11:59 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>  // ssize_t

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# if BUFFER_SIZE < 1
#  error Invalid value (BUFFER_SIZE) for the size of a buffer
# endif

char	*get_next_line(int fd);

ssize_t	ft_getdelim(char **line, size_t *linesize, int delim, FILE *fstream);
ssize_t	ft_getline(char **line, size_t *linesize, FILE *stream);

#endif
