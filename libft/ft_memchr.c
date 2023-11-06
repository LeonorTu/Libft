/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:43:54 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 21:05:42 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

//  #include <stdio.h>
//  #include <string.h>
//  int main()
//  {
//       char src1[] = "Bye";
//       char src2[] = "Hello, World!";
//       void *result1;
//       void *result2;
//       int c1 = 101;
//       int c2 = 108;

//       result1 = ft_memchr(src1, c1, 1);
//       printf("Source: %s\nc: %c\nReturn value: %s\n", src1, c1, (unsigned char*)result1);

//       result2 = ft_memchr(src2, c2, 3);
//       printf("Source: %s\nc: %c\nReturn value: %s\n", src2, c2, (unsigned char*)result2);
//       return (0);
//  	char *src = "/|\x12\xff\x09\x42\2002\42|\\";
//  	int size = 10;

//  	printf("%s", ft_memchr(src, '\200', size));

//  }
