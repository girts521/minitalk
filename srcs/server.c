/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:49:05 by girts             #+#    #+#             */
/*   Updated: 2024/09/11 20:03:16 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"

int ft_pow(int base, int exponent)
{
    int result = 1;
    while (exponent > 0) {
        result *= base;
        exponent--;
    }
    return result;
}

static int binary_to_int(const char *binary_str)
{
    int result = 0;
    int length = ft_strlen(binary_str);
    
    for (int i = 0; i < length; i++) {
        if (binary_str[i] == '1') {
            result += ft_pow(2, length - 1 - i);
        } else if (binary_str[i] != '0') {
            return (-1); 
        }
    }
    
    return result;
}

static void decrypt(char *letter)
{
	int ascii_letter;

	if (ft_strncmp(letter, "00000000", 8) == 0 )
		ft_putstr_fd("\n",1);
	else
	{
		ascii_letter = binary_to_int(letter);
		write(1, &ascii_letter, 1);
		ascii_letter = 0;
	}
}

void signal_handler(int signum)
{
	static char letter[8];
	static int	i = 0;
	char zero;
	char one;

	zero = '0';
	one = '1';
	if (i == 8)
	{
		i = 0;
		decrypt(letter);
	}
	if (signum == SIGUSR1)
	{
		letter[i] = zero;
		i++;
	}
	if (signum == SIGUSR2)
	{
		letter[i] = one;
		i++;
	}
}

int main(void)
{
	struct sigaction action;
	pid_t pid = getpid();
    printf("Server is running with pid: %d\n", pid);
	
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	sleep(1);
  while (1)
  {
	pause();
  }

  return 0;
}
