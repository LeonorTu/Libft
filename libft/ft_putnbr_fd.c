/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:37:37 by jtu               #+#    #+#             */
/*   Updated: 2023/11/03 20:39:06 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("print 42: \n");
// 	ft_putnbr_fd(42, 1);
// 	printf("\n");

// 	printf("print -233: \n");
// 	ft_putnbr_fd(-233, 1);
// 	printf("\n");

// 	printf("print 0: \n");
// 	ft_putnbr_fd(0, 1);
// 	printf("\n");

// 	printf("print 8: \n");
// 	ft_putnbr_fd(8, 1);
// 	printf("\n");

// 	printf("print -9: \n");
// 	ft_putnbr_fd(-9, 1);
// 	printf("\n");

// 	printf("print 2147483647: \n");
// 	ft_putnbr_fd(2147483647, 1);
// 	printf("\n");

// 	printf("print -2147483647-1: \n");
//     ft_putnbr_fd(-2147483648, 1);
//     printf("\n");
// }
