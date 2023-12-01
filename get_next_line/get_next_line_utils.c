/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:15:55 by jtu               #+#    #+#             */
/*   Updated: 2023/12/01 13:43:19 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
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

// char	*ft_strjoin(char *stash, char *buf)
// {
// 	int		i;
// 	int		j;
// 	char	*str;
// 	//int		len;

// 	// if (!stash)
// 	// 	len = 0;
// 	// else
// 	// 	len = ft_strlen(stash);
// 	if (!stash)
// 	{
// 		stash = malloc(sizeof(char) * 1);
// 		*stash = '\0';
// 	}
// 	if (!stash || !buf)
// 		return (NULL);
// 	str = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
// 	//if (!str)
// 	if (!str || !buf)
// 		return (free(str), free(buf), NULL);
// 	i = -1;
// 	j = 0;
// 	while (stash[++i])
// 		str[i] = stash[i];
// 	while (buf[j])
// 		str[i++] = buf[j++];
// 	str[ft_strlen(stash) + ft_strlen(buf)] = '\0';
// 	if (stash)
// 		free(stash);
// 	return (str);
// }

char	*ft_strjoin(char *stash, char *buf)
{
	int		i;
	int		j;
	char	*str;
	int		len;

	if (!stash)
		len = 0;
	else
		len = ft_strlen(stash);
	// if (!stash)
	// {
	// 	stash = malloc(sizeof(char) * 1);
	// 	*stash = '\0';
	// }
	// if (!stash || !buf)
	// 	return (NULL);
	str = malloc(sizeof(char) * (len + ft_strlen(buf) + 1));
	//if (!str)
	if (!str || !buf)
		return (free(str), free(buf), NULL);
	i = -1;
	j = 0;
	while (++i < len)
		str[i] = stash[i];
	while (buf[j])
		str[i++] = buf[j++];
	str[len + ft_strlen(buf)] = '\0';
	if (stash)
		free(stash);
	return (str);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}