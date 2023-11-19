/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:58:40 by jtu               #+#    #+#             */
/*   Updated: 2023/11/19 17:28:25 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * The printf() function writes output to
 * stdout, the standard output stream
 * @return the number of characters printed (not including
 * the trailing `\0' used to end output to strings)
*/
int	ft_printf(const char *fmt, ...)
{
	int			num;
	t_printf	print;

	va_start(print.args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			convert_spec(print, ++fmt);
		else
		{
			if (ft_putchar(fmt) == 1)
				print.num += 1;
			else
				return (-1);
		}
		fmt++;
		if (!fmt)
		{
			ft_putstr("(null)");
			va_end(print.args);
			return (print.num);
		}
	}
	va_end(print.args);
	return (print.num);
}
