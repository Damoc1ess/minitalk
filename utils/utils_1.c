/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:08:10 by fflamion          #+#    #+#             */
/*   Updated: 2024/07/29 16:09:42 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_putnbr(int n)
{
	long int	nbr;
	char		c;

	nbr = n;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + 48;
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	ft_atoi(char *str)
{
	int	neg;
	int	num;

	neg = 1;
	num = 0;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str)
	{
		num = num * 10 + *str - 48;
		str++;
	}
	return (num * neg);
}

void	reset_int_state(int *bit_count, int *trigger, int *len, int *i)
{
	*bit_count = 0;
	*trigger = 1;
	*len = 0;
	*i = 0;
}
