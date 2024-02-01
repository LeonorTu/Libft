/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:15:39 by jtu               #+#    #+#             */
/*   Updated: 2023/12/11 18:41:50 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **str)
{
	if (*str)
		free (*str);
	*str = NULL;
	return (NULL);
}

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
		return(ft_free(stash));
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
	{
		free(stash);
		return (NULL);
	}
	read_len = 1;
	while (!ft_strchr(stash, '\n') && read_len != 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		else if (read_len == 0)
			break ;
		buf[read_len] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_get_line(stash);
	stash = stash_update(stash);
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
// 	fd = open("test1.txt", O_RDONLY);

// 	line = get_next_line(fd);
// 	line = get_next_line(fd);
// 	line = get_next_line(fd);
// 	printf("%p",line);
// 	// while ((line = get_next_line(fd)))
// 	// {
// 	// 	printf("%d->%s\n", i++, line);
// 	// 	free(line);
// 	// }
// }
