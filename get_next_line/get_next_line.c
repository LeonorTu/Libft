/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonortu <leonortu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:15:39 by jtu               #+#    #+#             */
/*   Updated: 2023/11/28 22:10:49 by leonortu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char		*buf;
	char		*line;
	int			read_len;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buf, 0) < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(stash, '\n') && read_len != 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len <= 0)
			free(buf);
			return (NULL);
		buf[read_len] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (line);
}
