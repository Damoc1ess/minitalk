/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflamion <fflamion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:05:22 by fflamion          #+#    #+#             */
/*   Updated: 2024/07/29 11:05:29 by fflamion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 0x80)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c <<= 1;
		usleep(100);
		i++;
	}
}

void	send_str(int pid, const char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

void	send_len_and_separator(int pid, int len)
{
	char	*len_str;

	len_str = ft_itoa(len);
	if (!len_str)
	{
		ft_putstr("Memory allocation failed\n");
		exit(1);
	}
	send_str(pid, len_str);
	free(len_str);
	send_char(pid, ':');
}

int	main(int argc, char **argv)
{
	int	pid;
	int	len;

	if (argc != 3)
	{
		ft_putstr_red("Wrong number of arguments\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_red("Invalid PID\n");
		return (1);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_putstr_red("Empty message make sure to enter a message\n");
		return (0);
	}
	len = ft_strlen(argv[2]);
	send_len_and_separator(pid, len);
	send_str(pid, argv[2]);
	return (0);
}
