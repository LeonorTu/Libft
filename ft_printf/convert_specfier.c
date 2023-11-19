#include "ft_printf.h"

int convert_spec(va_list print, const char *fmt)
{
	if (fmt == 'c')
	{
		ft_putchar(va_arg(print.args, char));
		print.len++;
	}
	if (fmt == 's')
	{
		ft_putstr(va_arg(print.args, char *));
		print.len += ft_strlen(print.args);
	}
	if (fmt == 'p')
	{
		ft_putn(va_arg(print.args, unsigned long));
		//
	}
	if (fmt == 'd' || fmt == 'i')
	{
		ft_putnbr_base(va_arg(print.args, int), );
		//
	}
	if (fmt == 'u')
	{
		ft_putnbr_unsigned(va_arg(print.args, unsigned int));
		//
	}
	if (fmt == 'x' || fmt == 'X')
	{
		ft_puthex(va_arg(print.args, unsigned int));
		//
	}
	if (fmt == '%')
	{
		ft_putchar('%');
	}

}
