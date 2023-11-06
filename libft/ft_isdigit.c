/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:40:08 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:37:55 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(void)
// {
//     printf("Is 'a' a digit?\nft_isdigit result:%d\n", ft_isdigit('a'));
//     printf("isdigit result:%d\n", isdigit('a'));
// }
