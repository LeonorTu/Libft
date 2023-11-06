/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:48:39 by jtu               #+#    #+#             */
/*   Updated: 2023/11/06 12:44:32 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (--size && *src)
		*dst++ = *src++;
	*dst = 0;
	return (i);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	dst1[] = "hello";
// 	char	dst2[] = "hello";
// 	char	src[] = "Hello, World!";


// 	printf("Destination string: %s, Source string: %s\n", dst1, src);
// 	printf("strlcpy result: %zu, destination string: %s\n", strlcpy(dst1, src, 0), dst1);
// 	printf("ft_strlcpy result: %zu, destination string: %s\n", ft_strlcpy(dst2, src, 0), dst2);
// }
