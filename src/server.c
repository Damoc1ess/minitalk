/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:05:51 by fflamion          #+#    #+#             */
/*   Updated: 2024/07/29 22:05:04 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

typedef struct s_state
{
	int				bit_count;
	unsigned char	c;
	int				trigger;
	int				len;
	char			*str;
	int				i;
}				t_state;

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
	static t_state	s = {0, 0, 1, 0, NULL, 0};

	handle_bit(sig, &s.c, &s.bit_count);
	if (s.bit_count == 8)
	{
		if (s.trigger == 1)
		{
			process_length(&s.trigger, &s.len, s.c);
			if (!s.str && s.trigger == 0)
				s.str = malloc(s.len + 1);
		}
		else
		{
			process_character(&s.i, s.len, s.c, &s.str);
			if (s.i == s.len)
			{
				reset_int_state(&s.bit_count, &s.trigger, &s.len, &s.i);
				reset_char_state(&s.c, &s.str);
			}
		}
		s.bit_count = 0;
		s.c = 0;
	}
}

int	main(int argc, char **argv)
{
	argv[0] = NULL;
	if (argc != 1)
		return (0);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, sigusr_receiver);
	signal(SIGUSR2, sigusr_receiver);
	while (1)
		pause();
	return (0);
}
