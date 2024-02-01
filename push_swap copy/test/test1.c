long	ft_atoi_new(const char *str)
{
	long	value;
	long	sign;

	value = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		value = value * 10 + *str - '0';
		str++;
	}
	return (sign * value);
}

#include <stdio.h>
#include <limits.h>
int main(void)
{
	// long num = -2147483649;
	long num = ft_atoi_new("-2147483649");

	if (num < INT_MIN || num > INT_MAX)
    {
        printf("error: overflow\n");
    }
    else
    {
        printf("%ld\n", num);
    }
	// printf("%ld\n", num);
	// // if (num < INT_MIN)
	// printf("error");
	// return (0);
}
