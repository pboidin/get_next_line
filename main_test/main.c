/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piboidin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:26:53 by piboidin          #+#    #+#             */
/*   Updated: 2021/12/30 17:00:39 by piboidin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libc.h>

void	ft_read_line(int fd)
{
	char	*line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
}

int		main(int argc, char **argv)
{
	(void)argc;

	int fd1 = open(argv[1], O_RDONLY);

	ft_read_line(fd1);
}
