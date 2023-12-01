/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:15:39 by jtu               #+#    #+#             */
/*   Updated: 2023/12/01 13:27:31 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*stash_update(char *stash)
{
	int		i;
	int		j;
	char	*stash_new;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	stash_new = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!stash_new)
		return (NULL);
	j = 0;
	while (stash[i])
		stash_new[j++] = stash[i++];
	stash_new[j] = '\0';
	free(stash);
	return (stash_new);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	int		read_len;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_len = 1;
	while (!ft_strchr(stash, '\n') && read_len != 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if ((!stash && read_len == 0) || read_len == -1)
			return (free(buf), free(stash), NULL);
		// if ()
		// 	return (free(buf), stash);
		buf[read_len] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	return (free(buf), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash || !*stash)
		return (free(stash), NULL);
	line = ft_get_line(stash);
	// if (!line)
	// 	return (free(stash), free(line), NULL);
	stash = stash_update(stash);
	// if (!stash)
	// 	return (free(stash), free(line), NULL);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd;

// 	i = 1;
// 	fd = open("test2.txt", O_RDONLY);

// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%d->%s\n", i++, line);
// 		free(line);
// 	}
// }
