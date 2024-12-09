/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:49:05 by girts             #+#    #+#             */
/*   Updated: 2024/12/09 15:18:16 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	ft_pow(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent > 0)
	{
		result *= base;
		exponent--;
	}
	return (result);
}

static int	binary_to_int(const char *binary_str)
{
	int	result;
	int	length;
	int	i;

	i = 0;
	result = 0;
	length = ft_strlen(binary_str);
	while (i < length)
	{
		if (binary_str[i] == '1')
			result += ft_pow(2, length - 1 - i);
		else if (binary_str[i] != '0')
			return (-1);
		i++; 
	}
	return (result);
}

static void	decrypt(char *letter)
{
	int	ascii_letter;

	if (ft_strncmp(letter, "00000000", 8) == 0)
		ft_putstr_fd("\n", 1);
	else
	{
		ascii_letter = binary_to_int(letter);
		write(1, &ascii_letter, 1);
		ascii_letter = 0;
	}
}

void	signal_handler(int signum)
{
	static char	letter[8];
	static int	i = 0;

	if (i == 8)
	{
		i = 0;
		decrypt(letter);
	}
	if (signum == SIGUSR1)
		letter[i++] = '0';
	if (signum == SIGUSR2)
		letter[i++] = '1';
}

int	main(void)
{
	struct sigaction	action;	
	pid_t				pid;

	pid = getpid();
	printf("Server is running with pid: %d\n", pid);
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	sleep(250);
	while (1)
		pause();
	return (0);
}
