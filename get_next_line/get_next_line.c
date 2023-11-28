/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonortu <leonortu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:15:39 by jtu               #+#    #+#             */
/*   Updated: 2023/11/28 15:27:33 by leonortu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *rest;
	char		*buf;
	char		*line;
	int			read_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buf, 0) < 0)
		return (NULL);
	while ()
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
			free(buf);
			return (NULL);
		buf[read_len] = '\0';

		
	}
	return (line);
}
