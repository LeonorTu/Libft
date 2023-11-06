/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:44:56 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:54:15 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;
	size_t	all;

	all = count * size;
	memory = malloc(all);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, all);
	return (memory);
}

#include <stdio.h>

// int	main(void)
// {
// 	int	*str;
// 	int	i;

// 	str = ft_calloc(3, sizeof(int));
// 	i = 0;
// 	if (str == NULL)
// 		printf("Allocation fails!");
// 	while (i < 3)
// 	{
// 		if (str[i] != 0)
// 			printf("Allocated memory is not \
// 			filled with bytes of value zero.");
// 		str[i] = 2;
// 		printf("%d", str[i]);
// 		i++;
// 	}
// }
