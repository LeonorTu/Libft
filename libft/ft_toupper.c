/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:47:28 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 21:04:47 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(void)
// {
//     printf("Convert a to uppercase\nft_toupper result: %c\n", ft_toupper('a'));
// 	printf("toupper result: %c\n", toupper('a'));
// }
