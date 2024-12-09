/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gikarcev <gikarcev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:49:12 by girts             #+#    #+#             */
/*   Updated: 2024/12/09 20:11:21 by gikarcev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char	*num_to_binary(int nbr)
{
	int		nbr_final[8];
	int		i;
	char	*result;
	int		len;

	len = 0;
	i = 0;
	result = (char *)malloc(9);
	if (!result)
		return (NULL);
	ft_bzero(result, 9);
	while (len < 8)
	{
		nbr_final[len++] = nbr % 2;
		nbr = nbr / 2;
	}
	while (i < len)
	{
		result[i] = "01"[nbr_final[len - 1 - i]];
		i++;
	}
	result[len] = '\0';
	return (result);
}

void	send_signals(char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i])
	{
		usleep(500);
		if (message[i] == '0')
			kill(pid, SIGUSR1);
		else if (message[i] == '1')
			kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*binary;

	if (argc < 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		binary = num_to_binary(argv[2][i++]);
		send_signals(binary, pid);
		free(binary);
		binary = NULL;
	}
	send_signals("00000000", pid);
	return (0);
}
