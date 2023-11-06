/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:54:18 by jtu               #+#    #+#             */
/*   Updated: 2023/11/06 11:58:22 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	value;
	int	np;

	value = 0;
	np = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			np *= -1;
		str ++;
	}
	while (*str >= 48 && *str <= 57)
	{
		value = value * 10 + *str - '0';
		str ++;
	}
	return (np * value);
}
// #include <stdio.h>
// #include <stdlib.h>
// int main(int argc, char *argv[])
// {
// 	if (argc == 2)
// 	{
// 		printf("ft_atoi result:%d\n", ft_atoi(argv[1]));
// 		printf("atoi result:%d\n", atoi(argv[1]));
// 	}
// 	else
// 		printf("Error!");
// }
