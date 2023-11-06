/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:30:50 by jtu               #+#    #+#             */
/*   Updated: 2023/11/01 14:25:19 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}
// #include <stdio.h>
// int main(void)
// {
// 	char abcd[8] = "acdhsjbg";
// 	char str[12] = "Hello World!";
// 	char abc[4] = "acbg";
// 	int	i = 0;

// 	while (i < 10)
// 	{
// 		printf("The number of characters in \"%s\" is %ld.\n", str, ft_strlen(str));
// 		i++;
// 	}
// }
