/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:15:55 by jtu               #+#    #+#             */
/*   Updated: 2023/12/10 14:35:27 by jtu              ###   ########.fr       */
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
	char	*str;

	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		if (!stash)
			return (NULL);
		*stash = '\0';
	}
	if (!buf)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
	if (!str)
	{
		free(stash);
		buf = NULL;
		return (NULL);
	}
	i = -1;
	j = 0;
	while (stash[++i])
		str[i] = stash[i];
	while (buf[j])
		str[i++] = buf[j++];
	str[ft_strlen(stash) + ft_strlen(buf)] = '\0';
	free(stash);
	return (str);
}

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;

// 	i = 0;
// 	while (src[i])
// 		i++;
// 	if (dstsize == 0)
// 		return (i);
// 	while (--dstsize && *src)
// 		*dst++ = *src++;
// 	*dst = 0;
// 	return (i);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	unsigned int	i;
// 	unsigned int	len_dst;
// 	unsigned int	len_src;

// 	len_src = ft_strlen(src);
// 	if (size == 0)
// 		return (len_src + size);
// 	len_dst = ft_strlen(dst);
// 	if (size <= len_dst)
// 		return (len_src + size);
// 	i = 0;
// 	while (src[i] && i < size - len_dst - 1)
// 	{
// 		dst[i + len_dst] = src[i];
// 		i++;
// 	}
// 	dst[i + len_dst] = '\0';
// 	return (len_dst + len_src);
// }

// char	*ft_strdup(char *src)
// {
// 	char	*ptr;
// 	size_t	len;

// 	len = ft_strlen(src);
// 	ptr = (char *) malloc ((len + 1) * sizeof(char));
// 	if (!ptr)
// 	{
// 		free(src);
// 		return (NULL);
// 	}
// 	ft_strlcpy(ptr, src, len + 1);
// 	return (ptr);
// }

// char	*ft_strjoin(char *stash, char *buf)
// {
// 	char	*str;
// 	int		stash_len;
// 	int		buf_len;

// 	if (stash && buf)
// 	{
// 		stash_len = ft_strlen(stash);
// 		buf_len = ft_strlen(buf);
// 		str = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buf) + 1));
// 		if (!str)
// 			return (NULL);
// 		ft_strlcpy(str, stash, (stash_len + 1));
// 		ft_strlcat(str, buf, (stash_len + buf_len + 1));
// 		return (str);
// 	}
// 	else
// 	{
// 		if (!stash)
// 			return (ft_strdup(buf));
// 		else if (!buf)
// 			return (ft_strdup(stash));
// 	}
// 	return (NULL);
// }

