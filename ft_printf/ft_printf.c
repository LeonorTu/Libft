/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:58:40 by jtu               #+#    #+#             */
/*   Updated: 2023/11/16 16:44:02 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/**
 * The printf() function writes output to
 * stdout, the standard output stream
 * @return the number of characters printed (not including
 * the trailing `\0' used to end output to strings)
*/
int ft_printf(const char *format, ...)
{
	int	print_num;
	int	num;
	t_printf *print;

	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (0);
	va_start(print->args, format);
	while(*format)
	{
		if (*format == '%')

		else
		{
			num = write(1, &format, 1);
			if (num == 1)
				print_num += num;
			else
				return(num);
		}
		format++;
	}
	va_end(print->args);
	free(print);
	return (print_num);
}
