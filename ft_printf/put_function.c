/**
 * Outputs the integer ’n’ to the given file descriptor.
 * @param n - The integer to output.
 * @param fd - The file descriptor on which to write.
 */
int	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		if (ft_putchar('-') != 1)
			return (-1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		if (ft_putnbr(nbr / 10) != 1)
			return (-1);
		if (ft_putnbr(nbr % 10) != 1)
			return (-1);
	}
	else
		if (ft_putchar(nbr + '0') != 1)
			return (-1);
	return (1);
}

/**
 * Outputs the unsigned integer ’n’ to the given bases.
 * @param n - The unsigned integer to output.
 */
int	ft_putnbr_base(unsigned long long n, char *base)
{
	long	nbr;
	int		base_len;

	nbr = n;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		if (ft_putnbr_base(nbr / base_len, base) != 1)
			return (-1);
		if (ft_putnbr_base(nbr % base_len, base) != 1)
			return (-1);
	}
	else
		if (ft_putchar(nbr + base) != 1)
			return (-1);
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

int	ft_puthex(unsigned int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		if (ft_putchar('-') != 1)
			return (-1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		if (ft_putnbr(nbr / 16) != 1)
			return (-1);
		if (ft_putnbr(nbr % 10) != 1)
			return (-1);
	}
	else
		if (ft_putchar(nbr + '0') != 1)
			return (-1);
	return (1);
}

ft_putaddress()
{

}
