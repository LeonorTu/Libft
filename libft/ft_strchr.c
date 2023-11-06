/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:46:51 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:37:44 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (c == *s)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char s[] = "Hello, World!";
//     int c = 3;

//     printf("s = %s, c = %c, ft_strchr result:%s\n", s, c, ft_strchr(s, c));
//     printf("s = %s, c = %c, strchr result:%s\n", s, c, strchr(s, c));
// }
