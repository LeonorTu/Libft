/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:45:43 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:55:04 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(void)
// {
//     printf("Is 'c' an alphabet?\nft_isalpha result:%d\n", ft_isalpha('c'));
//     printf("isalpha result:%d\n", isalpha('a'));
// }
