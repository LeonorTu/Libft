/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:58:40 by jtu               #+#    #+#             */
/*   Updated: 2023/11/21 17:41:33 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise_list(t_printf *print)
{
	print->len = 0;
}

/**
 * The printf() function writes output to
 * stdout, the standard output stream
 * @return the number of characters printed (not including
 * the trailing `\0' used to end output to strings)
*/
int	ft_printf(const char *fmt, ...)
{
	t_printf	print;

	initialise_list(&print);
	va_start(print.args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (convert_spec(&print, ++fmt) != 1)
				return (-1);
		}
		else
		{
   			if (ft_putchar(*fmt) == 1)
 				print.len += 1;
			else
				return (-1);
		}
		fmt++;
	}
	va_end(print.args);
	return (print.len);
}

// #include <stdio.h>
// #include <limits.h>
// int	main(void)
// {
// 	// int c1 = ft_printf("%c\n", '0');
// 	// int c2 = printf("%c\n", '0');
// 	// printf("ft_printf: %d\n", c1);
// 	// printf("printf: %d\n", c2);

// 	// int c3 = ft_printf(" %d\n", -11);
// 	// int c4 = printf(" %d\n", -11);
// 	// printf("ft_printf: %d\n", c3);
// 	// printf("printf: %d\n", c4);

// 	// int c5 = ft_printf("%p\n", (void*)1);
// 	// int c6 = printf("%p\n", (void*)1);
// 	// printf("ft_printf: %d\n", c5);
// 	// printf("printf: %d\n", c6);

// 	// int c7 = ft_printf("%x\n", LONG_MIN);
// 	// int c8 = printf("%x\n", LONG_MIN);
// 	// printf("ft_printf: %d\n", c7);
// 	// printf("printf: %d\n", c8);

// 	// int c9 = ft_printf("%u\n", -10);
// 	// int c10 = printf("%u\n", -10);
// 	// printf("ft_printf: %d\n", c9);
// 	// printf("printf: %d\n", c10);

// 	int c11 = ft_printf("%p %p \n", LONG_MIN, LONG_MAX);
// 	int c12 = printf("%p %p \n", LONG_MIN, LONG_MAX);
// 	printf("ft_printf: %d\n", c11);
// 	printf("printf: %d\n", c12);

// 	// int c13 = printf(" NULL %s NULL ", NULL);
// 	// printf("printf: %d\n", c13);
// 	// int c14 = ft_printf(" NULL %s NULL ", NULL);
// 	// printf("printf: %d\n", c14);
// }
