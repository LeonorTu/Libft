/**
 * Outputs the character ’c’ to the given file descriptor.
 * @param n - The integer to output.
 * @param fd - The file descriptor on which to write.
 */
int	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10);
		ft_putnbr_fd(nbr % 10);
	}
	else
		ft_putchar_fd(nbr + '0');
	return (1);
}

/**
 * Outputs the character ’c’ to the given file descriptor.
 */
int	ft_putchar(char c)
{
	return(write(1, &c, 1));
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
		if (write(1, s, 1) < 0)
			return (-1);
		s++;
	}
	return (1);
}
