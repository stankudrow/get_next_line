/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanislav <student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:21:06 by stanislav         #+#    #+#             */
/*   Updated: 2022/06/22 13:21:15 by stanislav        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getline.h"

int	main(void)
{
	char	*str;
	ssize_t	nbytes;
	size_t	bufsiz;

	str = NULL;
	bufsiz = 0;
	fputs("stdin: ", stdout);
	nbytes = ft_getline(&str, &bufsiz, stdin);
	if (nbytes < 0)
		fprintf(stderr, "stderr: %d error occured.\n", errno);
	else
		fprintf(stdout, "\nstdout: %s\n{%ld bytes | len = %zu}\n", str, nbytes, bufsiz);
	free(str);
	return (0);
}
