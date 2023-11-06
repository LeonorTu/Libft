/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:40:24 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:39:47 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)c;
	return (s);
}

// #include <stdio.h>
// int main()
// {

//     int arr[5];
//     size_t n = sizeof(arr) / sizeof(arr[0]);

//     // Initialize the entire array to 0
//     ft_memset(arr, 3, n * sizeof(int));

//     // Print the initialized array
//     for (size_t i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return (0);
//     //int s = 48;
//     //int i = 0;

//     //while (i < 3)
//     //{
//        // printf("%c", ((char*)ft_memset(s, 2, 3))[i++]);
//     //}
// }
