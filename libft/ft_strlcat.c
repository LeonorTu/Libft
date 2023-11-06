/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:30:00 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 21:04:34 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len_dst;
	unsigned int	len_src;

	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src + size);
	len_dst = ft_strlen(dst);
	if (size < len_dst)
		return (len_src + size);
	i = 0;
	while (src[i] && i < size - len_dst - 1)
	{
		dst[i + len_dst] = src[i];
		i++;
	}
	dst[i + len_dst] = '\0';
	return (len_dst + len_src);
}

// #include <stdio.h>
// #include <string.h>
//  int main(void)
//  {
//   	size_t n;
//   	char str1[20] = "This is 5\n31\t313";
//   	char str2[20] = "This is 5\n31\t313";
//   	char str3[] = "a test.";

//   	n = 3;
//   	printf("Print str1: %s\n", str1);
//   	printf("Print str3: %s\n", str3);
//   	printf("Concatenate str1 and str2 for %zu -1 characters\n", n);
//   	 the resultant string is stored in str1.
//   	ft_strlcat(str1, str2, n);
//   	printf("strlcat result: \nPrint str1: %s and return value: %zu\n", str2,strlcat(str2, str3, n));
//   	printf("ft_strlcat result: \nPrint str1: %s and return value: %zu\n", str1, ft_strlcat(str1, str3, n));
//  	char str[50] = "";

//  	printf("%lu\n", ft_strlcat(str, "world", 0));
//  }
