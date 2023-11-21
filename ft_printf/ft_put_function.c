/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:41:03 by jtu               #+#    #+#             */
/*   Updated: 2023/11/21 18:51:08 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Outputs the unsigned integer ’n’ to the given bases.
 * @param n - The unsigned integer to output.
 */
int	ft_putnbr_base(long nbr, char *base, char type)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr < 0 && type == 'd')
	{
		if (ft_putchar('-') != 1)
			return (-1);
		nbr = -nbr;
	}
	else
		nbr = (unsigned int) nbr;
	if (nbr >= base_len)
	{
		if (ft_putnbr_base(nbr / base_len, base, type) != 1)
			return (-1);
		if (ft_putnbr_base(nbr % base_len, base, type) != 1)
			return (-1);
	}
	else
		if (write(1, (base + nbr), 1) != 1)
			return (-1);
	return (1);
}

/**
 * Outputs the character ’c’ to the given file descriptor.
 */
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * Outputs the string ’s’ to the given file descriptor.
 * @param s - The string to output.
 * @param fd - The file descriptor on which to write.
 */
int	ft_putstr(char *s)
{
	while (*s)
	{
		if (ft_putchar(*s) < 0)
			return (-1);
		s++;
	}
	return (1);
}

int	ft_numlen_base(long nbr, char *base, char type)
{
	int	len;
	int	base_len;

	if (type != 'd')
		nbr = (unsigned int)nbr;
	base_len = ft_strlen(base);
	len = 0;
	if (nbr < 1)
		len++;
	while (nbr)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}
