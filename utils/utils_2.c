/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:15:19 by fflamion          #+#    #+#             */
/*   Updated: 2024/07/29 16:09:42 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

static int	int_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		ncpy;
	int		i;
	char	*str;

	if (n == -2147483648)
		return ("-2147483648");
	ncpy = n;
	if (n < 0)
		ncpy = -n;
	i = int_len(n);
	str = (char *)malloc(sizeof(char) * (i));
	if (!str)
		return (NULL);
	i--;
	if (ncpy == 0)
		str[i] = '0';
	while (ncpy > 0)
	{
		str[i--] = (ncpy % 10) + '0';
		ncpy /= 10;
	}
	if (n < 0)
		str[i] = '-';
	return (str);
}

void	ft_putstr_red(const char *str)
{
	write(1, "\033[31m", 5);
	write(1, str, ft_strlen(str));
	write(1, "\033[0m", 4);
}

void	reset_char_state(unsigned char *c, char **str)
{
	*c = 0;
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
