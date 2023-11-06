/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:47:18 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:37:35 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (c == s[i])
			return (char *)(s + i);
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char s[] = "Hello, World!";
//     int c = 0;

//     printf("s = %s, c = %c, ft_strcrhr result:%s\n", s, c, ft_strrchr(s, c));
//     printf("s = %s, c = %c, strrchr result:%s\n", s, c, strrchr(s, c));
// }
