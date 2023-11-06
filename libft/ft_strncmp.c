/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:28:42 by jtu               #+#    #+#             */
/*   Updated: 2023/10/27 18:16:02 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}	

// #include <stdio.h>
// #include <string.h>
// int main() {
// 	char str1[] = "a/0bcd", str2[] = "a/200bCd", str3[] = "aBcd ";
// 	unsigned int	n;

// 	printf("str1 = %s, str2 = %s, str3 = %s.\n", str1, str2, str3);
// 	n = 3;
// 	printf("n = %d\n", n);
// 	// comparing strings str1 and str2
// 	printf("ft_strncmp(str1, str2, n) = %d\n", ft_strncmp(str1, str2, n));
// 	printf("strncmp(str1, str2, n) = %d\n", strncmp(str1, str2, n));
// 	// comparing strings str1 and str3
// 	printf("ft_strncmp(str1, str3, n) = %d\n", ft_strncmp(str1, str3, n));
// 	printf("strncmp(str1, str3, n) = %d\n", strncmp(str1, str3, n));
// 	return 0;
// }