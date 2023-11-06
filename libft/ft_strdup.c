/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:38:34 by jtu               #+#    #+#             */
/*   Updated: 2023/10/30 18:06:51 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(src);
	ptr = (char *) malloc ((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, src, len + 1);
	return (ptr);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	// char src[] = "HAHAHA \0 tu me vois pas !";

// 	// printf("%s\n", strdup(src));

// 	char *str;
// 	char *tmp = "I malloc so I am.";

// 	str = ft_strdup(tmp);
// }
