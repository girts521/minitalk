/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:49:05 by girts             #+#    #+#             */
/*   Updated: 2024/07/29 23:02:01 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"

int ft_pow(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        result *= base;
        exponent--;
    }
    return result;
}

static int binary_to_int(const char *binary_str) {
    int result = 0;
    int length = ft_strlen(binary_str);
    
    for (int i = 0; i < length; i++) {
        if (binary_str[i] == '1') {
            result += ft_pow(2, length - 1 - i);
        } else if (binary_str[i] != '0') {
            // Handle invalid characters
            return -1; // Error code for invalid input
        }
    }
    
    return result;
}

static void decrypt(char *letter)
{
	int ascii_letter;
	// char **message;

	// ascii_letter = 0;
	if (ft_strncmp(letter, "00000000", 8) == 0 )
	{
		// ft_putstr_fd("here\n",1);
		// printf("here: %d\n", ft_strncmp(letter, "00000000", 8));
		// ft_putstr_fd(letter, 1);
		ft_putstr_fd("\n",1);
	}
	else
	{
		// ft_printf("letter: %s\n", letter);
		// ft_putstr_fd(letter,1);
		// ft_putstr_fd("\n",1);
		ascii_letter = binary_to_int(letter);
		// ft_printf("num: %d\n", ascii_letter);
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
		// ft_printf("%s\n", letter);
		decrypt(letter);
	}
	if (signum == SIGUSR1)
	{
		letter[i] = zero;
		i++;
	}
		// write(1, &zero, 1);
	if (signum == SIGUSR2)
	{
		letter[i] = one;
		i++;
	}


		// write(1, &one, 1);
	// if (signum == SIGUSR1)
	// {
	// 	if (i < 7)
	// 	{			
	// 		letter[i] = zero;
	// 		i++;
	// 	}
	// 	if (i == 7)
	// 	{
			
	// 		letter[i] = zero;
	// 		i = 0;
	// 		// decrypt(letter);
	// 		ft_putstr_fd(letter,1);
	// 	}
	// }
	// if (signum == SIGUSR2)
	// {
	// 	if (i < 7)
	// 	{
	// 		letter[i] = one;
	// 		i++;
	// 	}
	// 	if (i == 7)
	// 	{
	// 		letter[i] = one;
	// 		i = 0;
	// 		// decrypt(letter);
	// 		ft_putstr_fd(letter,1);
	// 	}
	// }

	
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
    // Do some work
	pause();
  }

  return 0;
}

// int main(void)
// {
//     pid_t pid = getpid();
//     printf("Server is running with pid: %d...\n", pid);

//     struct sigaction action;
//     ft_memset(&action, 0, sizeof(action));

//     // Set up the signal handler
//     action.sa_handler = signal_handler;

//     // Initialize signal sets
//     sigemptyset(&action.sa_mask);
//     action.sa_flags = 0;

//     // Register the signal handlers
//     sigaction(SIGUSR1, &action, NULL);
//     sigaction(SIGUSR2, &action, NULL);

//     // Keep the program running to receive signals
//     sleep(600);

//     return 0;
// }
