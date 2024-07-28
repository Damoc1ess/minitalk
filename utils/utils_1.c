#include "../include/minitalk.h"

void ft_putnbr(int n)
{
	long int (nbr);
	nbr = n;
	char c;

	if (nbr < 0)
	{
		write(1,"-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + 48;
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int ft_atoi(char *str)
{
	int neg;
	int num;

	neg = 1;
	num = 0;
	if(*str == '-')
	{
		neg= -1;
		str++;
	}
	while (*str)
	{
		num = num * 10 + *str - 48;
		str++;
	}
	return (num * neg);
}
