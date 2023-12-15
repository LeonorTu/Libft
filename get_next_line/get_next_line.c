/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:15:39 by jtu               #+#    #+#             */
/*   Updated: 2023/12/15 15:00:28 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static int	ft_free_strs(char *str1, char *str2)
{
	free(str1);
	free(str2);
	return (-1);
}

static int	ft_get_line(char **stash, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
	{
		*line = ft_substr(*stash, 0, i + 1);
		if (!(*line))
			return (-1);
		temp = ft_substr(*stash, i + 1, ft_strlen(*stash) - i - 1);
		if (!temp)
		{
			free(*line);
			return (-1);
		}
		free(*stash);
		*stash = temp;
		return (1);
	}
	return (0);
}

static int	read_to_stash(int fd, char **stash)
{
	int		read_len;
	char	*temp;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	read_len = read(fd, buf, BUFFER_SIZE);
	while (read_len > 0)
	{
		buf[read_len] = '\0';
		if (!*stash)
			*stash = ft_strdup("");
		temp = *stash;
		*stash = ft_strjoin(temp, buf);
		if (!*stash)
			return (ft_free_strs(temp, buf));
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
		read_len = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (read_len);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			status;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
			ft_free(&stash);
		return (NULL);
	}
	status = read_to_stash(fd, &stash);
	if (!stash || !*stash || status < 0 || ft_get_line(&stash, &line) < 0)
		return (ft_free(&stash));
	if (line)
		return (line);
	if (stash && *stash != '\0')
	{
		line = ft_strdup(stash);
		ft_free(&stash);
	}
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
// 	fd = open("test4.txt", O_RDONLY);

// 	// line = get_next_line(fd);
// 	// line = get_next_line(fd);
// 	// line = get_next_line(fd);
// 	// printf("%p",line);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%d->%s", i++, line);
// 		free(line);
// 	}
// }
