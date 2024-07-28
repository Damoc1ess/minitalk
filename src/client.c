#include "../include/minitalk.h"

void send_len(int len, int pid)
{
	char c;
	char *lenght;
	int i;

	i = 0;
	lenght = ft_itoa(len);
	while (*lenght)
	{
		c = *lenght;
		while (i != 8)
		{
			if (c & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			c = c << 1;
			i++;
			usleep(1000);
		}
		i = 0;
		lenght++;
	}
}

void send_sig(int pid, char *str)
{
	int i;
	char c;
	int trigger = 1;
	
	if (trigger == 1)
		send_len(ft_strlen(str), pid);
	i = 0;
	while (*str)
	{
		c = *str;
		while (i != 8)
		{
			if (c & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			c = c << 1;
			i++;
			usleep(1000);
		}
		i = 0;
		str++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	else
	{
		send_sig(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}