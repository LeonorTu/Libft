#include <unistd.h>
#include <stdio.h>

int main()
{
	write(1, -9223372036854775808 + "0123456789ABCDEF", 1);
	//printf(NULL, "sss");
}

// /**
//  * Outputs the integer ’n’ to the given file descriptor.
//  * @param n - The integer to output.
//  * @param fd - The file descriptor on which to write.
//  */
// int	ft_putnbr(int n)
// {
// 	long	nbr;

// 	nbr = n;
// 	if (nbr < 0)
// 	{
// 		if (ft_putchar('-') != 1)
// 			return (-1);
// 		nbr = -nbr;
// 	}
// 	if (nbr >= 10)
// 	{
// 		if (ft_putnbr(nbr / 10) != 1)
// 			return (-1);
// 		if (ft_putnbr(nbr % 10) != 1)
// 			return (-1);
// 	}
// 	else
// 		if (ft_putchar(nbr + '0') != 1)
// 			return (-1);
// 	return (1);
// }


// int	ft_puthex(unsigned int n)
// {
// 	long	nbr;

// 	nbr = n;
// 	if (nbr < 0)
// 	{
// 		if (ft_putchar('-') != 1)
// 			return (-1);
// 		nbr = -nbr;
// 	}
// 	if (nbr >= 10)
// 	{
// 		if (ft_putnbr(nbr / 16) != 1)
// 			return (-1);
// 		if (ft_putnbr(nbr % 10) != 1)
// 			return (-1);
// 	}
// 	else
// 		if (ft_putchar(nbr + '0') != 1)
// 			return (-1);
// 	return (1);
// }

	// if (!fmt)
	// {
	// 	ft_putstr("(null)");
	// 	return (6);
	// }
