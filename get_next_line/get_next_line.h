/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:15:52 by jtu               #+#    #+#             */
/*   Updated: 2023/12/15 15:58:09 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *stash, char *buf);
char	*ft_strdup(const char *src);
int		ft_strlen(const char *str);

#endif
