/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:05:51 by fflamion          #+#    #+#             */
/*   Updated: 2024/07/29 11:31:51 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	reset_state(int *bit_count, unsigned char *c, int *trigger, int *len, char **str, int *i)
{
	*bit_count = 0;
	*c = 0;
	*trigger = 1;
	*len = 0;
	*i = 0;
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	handle_bit(int sig, unsigned char *c, int *bit_count)
{
	if (sig == SIGUSR2)
		*c = (*c << 1);
	else if (sig == SIGUSR1)
		*c = (*c << 1) | 1;
	(*bit_count)++;
}

void	process_length(int *trigger, int *len, unsigned char c)
{
	if (c == ':')
		*trigger = 0;
	else
		*len = *len * 10 + (c - '0');
}

void	process_character(int *i, int len, unsigned char c, char **str)
{
	(*str)[*i] = c;
	(*i)++;
	if (*i == len)
	{
		(*str)[*i] = '\0';
		ft_putstr(*str);
		free(*str);
		*str = NULL;
	}
}

void	sigusr_receiver(int sig)
{
	static int		bit_count = 0;
	static unsigned char c = 0;
	static int		trigger = 1;
	static int		len = 0;
	static char		*str = NULL;
	static int		i = 0;

	handle_bit(sig, &c, &bit_count);
	if (bit_count == 8)
	{
		if (trigger == 1)
		{
			process_length(&trigger, &len, c);
			if (!str && trigger == 0)
				str = malloc(len + 1);
		}
		else
		{
			process_character(&i, len, c, &str);
			if (i == len)
				reset_state(&bit_count, &c, &trigger, &len, &str, &i);
		}
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, sigusr_receiver);
	signal(SIGUSR2, sigusr_receiver);
	while (1)
		pause();
	return (0);
}
