/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:15:55 by jtu               #+#    #+#             */
/*   Updated: 2023/12/13 16:39:22 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *stash, char *buf)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (!stash || !buf)
		return (NULL);
	len = ft_strlen(stash) + ft_strlen(buf);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (stash[++i])
		str[i] = stash[i];
	while (buf[j])
		str[i++] = buf[j++];
	str[len] = '\0';
	return (str);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*sub_s;
	int		i;

	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_s = malloc(len * sizeof(char) + 1);
	if (!sub_s)
		return (NULL);
	i = 0;
	while (i < len && i + start < ft_strlen(s))
	{
		sub_s[i] = s[i + start];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	size_t	count;
	size_t	i;

	count = ft_strlen((char *)src);
	ptr = (char *)malloc((count + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
