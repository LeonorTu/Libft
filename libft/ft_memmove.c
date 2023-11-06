/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:48:13 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:39:14 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest2 == src2 || n == 0)
		return (dest);
	else if (dest2 < src2)
		ft_memcpy(dest2, src2, n);
	else
	{
		while (--n >= 0)
		{
			dest2[n] = src2[n];
			if (n == 0)
				break ;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     // char src1[] = "Bye";
//     // //ft_memmove(src1 + 1, src1, 2);
//     // int src2[3] = {1,30,3};
//     // char dest[] = "Hello, World!";

//     // printf("Before memmove:\n");
//     // printf("Destination: %s\n", dest);

//     // ft_memmove(dest, src1, 3);
//     // printf("After first ft_memmove:\n");
//     // printf("Destination: %s\n", dest);

//     // ft_memmove(dest, src2, 12);
//     // printf("After second ft_memmove:\n");
//     // printf("Destination: %d\n", dest[0]);
//     printf("dddd\n");
//     if (ft_memmove("", "" - 1, 0) == memmove("", "" - 1, 0))
//         printf("correct\n");
//     else
//         printf("wrong\n");
//     printf("yes\n");
// }
