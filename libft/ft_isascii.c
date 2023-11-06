/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:47:29 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:38:06 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <wctype.h>
// #include <stdio.h>
// int main(void)
// {
//     printf("Is 'ö' ascii?\nft_isascii result:%d\n", ft_isascii(L'ö'));
//     printf("isascii result:%d\n", isascii(L'ö'));
// }
