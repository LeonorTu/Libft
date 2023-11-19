/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:46:21 by jtu               #+#    #+#             */
/*   Updated: 2023/11/19 16:23:24 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct	s_printf{
	va_list	args;
	int	num;
}	t_printf;

# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"

#endif
