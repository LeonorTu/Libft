/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:46:07 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:37:51 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

// #include <ctype.h>
// #include <wctype.h>
// #include <stdio.h>
// int main(void)
// {
//     printf("Is 'a' printable?\nft_isprint result:%d\n", ft_isprint('a'));
//     printf("isprint result:%d\n", isprint('a'));
//     printf("Is 'ö' printable?\nft_isprint result:%d\n", ft_isprint(L'ö'));
//     printf("isprint result:%d\n", isprint(L'ö'));
// }
