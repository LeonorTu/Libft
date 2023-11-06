/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:47:00 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:39:52 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 */
int	count_len(int n)
{
	int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*str;
	int		i;

	nbr = n;
	len = count_len(nbr);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	i = len - 1;
	while (i >= 0 && nbr >= 0)
	{
		str[i--] = nbr % 10 + 48;
		nbr /= 10;
		if (nbr == 0)
			break ;
	}
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     char *n1 = ft_itoa(-623);
// 	char *n2 = ft_itoa(156);
// 	char *n3 = ft_itoa(-0);
// 	char *n4 = ft_itoa(-2147483648);

// 	if (strcmp(n1, "-623"))
//         printf("FAIL!\n");
//     else
//         printf("SUCCESS!\n");
//     if (strcmp(n2, "156"))
//         printf("FAIL!\n");
//     else
//         printf("SUCCESS!\n");
//     if (strcmp(n3, "0"))
//         printf("FAIL!\n");
//     else
//         printf("SUCCESS!\n");
//     if (strcmp(n4, "-2147483648"))
//         printf("FAIL!\n");
//     else
//         printf("SUCCESS!\n");
// }
