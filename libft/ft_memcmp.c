/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:46:20 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 21:06:19 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	s1_char = (unsigned char *)s1;
	s2_char = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_char != *s2_char)
			return (*s1_char - *s2_char);
		s1_char++;
		s2_char++;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
//     char s1[13] = "Hello, World!";
//     char s2[14] = "Hello, World!";
//     char s3[5] = {'a', 'b', 'c', '\0', 't'};
//     char s4[5] = {'a', 'b', 'c', '\0', 'f'};

//     printf("s1: %s, s2: %s\nft_memcmp result:%d\n", s1, s2, ft_memcmp(s1, s2, 14));
//     printf("s1: %s, s2: %s\nft_strcmp result: %d\n", s3, s4, ft_strncmp(s3, s4, 5));
//     printf("ft_memcmp result: %d\n", ft_memcmp(s3, s4, 5));
// }
