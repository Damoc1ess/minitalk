#include "../include/minitalk.h"

void sigusr_receiver(int sig)
{
	static int bit_count = 0;
	static unsigned char c = 0;
	static int trigger = 1;
	static int len = 0;
	static char *str;
	static int i = 0;

	if (sig == SIGUSR2)
		c = c << 1;
	else if (sig == SIGUSR1)
		c = c << 1 | 1;
	bit_count++;

	if (bit_count == 8 && trigger == 1)
	{
		if (c == ':')
		{
			trigger = 0;
			bit_count = 0;
			str = malloc(sizeof(char) * (len + 1));
		}	
		else
		{
			len = len * 10 + c - '0';
			bit_count = 0;
		}
	}
	if (bit_count == 8)
	{
		str[i] = 'c';
		i++;
		c = 0;
		bit_count = 0;
	}
}

int main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, sigusr_receiver);
	signal(SIGUSR2, sigusr_receiver);
	while (1)
		pause(); // Wait for signals
	return (0);
}