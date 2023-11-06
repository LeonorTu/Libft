/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:44:04 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:56:27 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (src2[i] == c)
			return ((void *)(dest2 + i));
		dest2[i] = src2[i];
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	src1[] = "Bye";
// 	int		src2[3] = {1, 30, 3};
// 	char	dest[] = "Hello, World!";
// 	void	*result;

// 	printf("Before ft_memmove:\n");
// 	printf("Destination: %s\n", dest);
// 	result = ft_memccpy(dest, src1, 100, 3);
// 	printf("After ft_memccpy:\n");
// 	printf("Destination: %s\n Return value: %s\n", \
// 		dest,(unsigned char *)result);
// 	// ft_memccpy(dest, src2, "l", 12);
// 	// printf("After second memmove:\n");
// 	// printf("Destination: %d\n", dest[0]);
// 	return (0);
// }
