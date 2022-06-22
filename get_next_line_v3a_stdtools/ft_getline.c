/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:18:46 by stanislav         #+#    #+#             */
/*   Updated: 2022/06/20 21:18:47 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getline.h"

ssize_t	ft_getline(char **line, size_t *linesize, FILE *stream)
{
	return (ft_getdelim(line, linesize, '\n', stream));
}
