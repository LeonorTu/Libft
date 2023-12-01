/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:15:52 by jtu               #+#    #+#             */
/*   Updated: 2023/11/30 20:54:29 by jtu              ###   ########.fr       */
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
//char	*read_to_stash(int fd, char *stash);
//char	*ft_get_line(char *stash);
//char	*stash_update(char *stash);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *stash, char *buf);
int	ft_strlen(const char *str);

#endif
