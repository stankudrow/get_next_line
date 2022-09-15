/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:14:20 by stanislav         #+#    #+#             */
/*   Updated: 2022/09/15 11:07:38 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETLINE_H
# define FT_GETLINE_H

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

ssize_t	ft_getdelim(char **line, size_t *linesize, int delim, FILE *fstream);
ssize_t	ft_getline(char **line, size_t *linesize, FILE *stream);

#endif
