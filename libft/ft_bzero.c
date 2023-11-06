/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:45:21 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:38:46 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>
// int main()
// {

//     int arr[5];
//     size_t i = 0;
//     size_t n = sizeof(arr) / sizeof(arr[0]);

//     // Initialize the entire array to 0
//     ft_bzero(arr, n * sizeof(int));

//     // Print the initialized array
//     while(i < n)
//         printf("%d\n", arr[i++]);
//     printf("\n");

//     return 0;
// }
