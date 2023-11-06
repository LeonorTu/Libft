/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:47:10 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:37:37 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*s1_temp;
	char	*s2_temp;

	s1_temp = (char *)s1;
	s2_temp = (char *)s2;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1_temp && n)
	{
		if (*s1_temp == *s2_temp)
			s2_temp++;
		s1_temp++;
		n--;
		if (*s2_temp == '\0')
			return ((char *)(s1_temp - (s2_temp - s2)));
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {

// 	// char * teststd = strnstr(((void *)0), "fake", 3);
// 	char * testft = ft_strnstr(((void *)0), "fake", 3);
// 	char str[] = "jhhk";
// 	char to_find[] = "";
// 	// printf("strnstr result: %s\n", strnstr(str, to_find, 0));
// 	// printf("ft_strnstr result: %s\n", ft_strnstr(str, to_find, 0));
// 	// printf("strnstr result: %s\n", teststd);
// 	printf("ft_strnstr result: %s\n", testft);
// }
