/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:05:11 by ixu               #+#    #+#             */
/*   Updated: 2023/11/13 16:46:53 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = open("tests/lorem_ipsum.txt", O_RDONLY);
	// printf("%d\n", fd);

	next_line = get_next_line(fd);
	while (next_line != NULL)
	{
		printf("%s", next_line);
		free(next_line);
		next_line = get_next_line(fd);
	}

	// printf("---1st call of the function---\n");
	// printf("%p\n", get_next_line(fd));
	// printf("---2st call of the function---\n");
	// printf("%p\n", get_next_line(fd));
	// printf("---3rd call of the function---\n");
	// printf("%p\n", get_next_line(fd));
	// printf("---4th call of the function---\n");
	// printf("%p\n", get_next_line(fd));
	// printf("---5th call of the function---\n");
	// printf("%p\n", get_next_line(fd));
	// printf("---6thrd call of the function---\n");
	// printf("%p\n", get_next_line(fd));
	// printf("---7thrd call of the function---\n");
	// printf("%p\n", get_next_line(fd));

	close(fd);

	return (0);	
}
