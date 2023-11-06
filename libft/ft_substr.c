/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:44:40 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:37:31 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	sub_s = malloc(len * sizeof(char) + 1);
	if (!sub_s)
		return (NULL);
	i = 0;
	while (i < len && i + start < ft_strlen(s))
	{
		sub_s[i] = s[i + start];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

// #include <stdio.h>
// int main(void)
// {
//     char *s = "Hello, World!";

//     printf("string: %s", s);
//     printf("substring: %s", ft_substr(s, 2, 0));
// }
