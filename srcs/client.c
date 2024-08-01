/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:49:12 by girts             #+#    #+#             */
/*   Updated: 2024/07/29 23:09:45 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

char *num_to_binary(int nbr)
{
	int	nbr_final[8];
	int	i;
	char	*result;
	int	len;
	char	*base;

	base = "01";
	i = 0;
	result = (char *)malloc(9);
	if (!result)
		return (NULL);
	ft_bzero(result, 9);

	if (nbr < 0)
		nbr = 256 + nbr;

	while (i < 8)
	{
		nbr_final[i] = nbr % 2;
		nbr = nbr / 2;
		i++;
	}

	len = i;
	i = 0;
	while ( i < len)
	{
		result[i] = base[nbr_final[len - 1 - i]];
		i++;
	}

	result[len] = '\0';
	return (result);
}

// char	*num_to_binary(int nbr)
// {
// 	int	size_base;
// 	int	nbr_final[100];
// 	int	i;
// 	char	*result;
// 	int len;
// 	char *base;

// 	base = "01";
// 	i = 0;
// 	size_base = 0;
// 	result = (char *)malloc(sizeof(char) * 100);
// 	if (!result)
// 		return (NULL);
// 	ft_bzero(result, 100);
// 	if (check_base(base))
// 	{
// 		if (nbr < 0)
// 		{
// 			nbr = -nbr;
// 			result[0] = '-';
// 			i++;
// 		}
// 		while (base[size_base])
// 			size_base++;
// 		while (nbr)
// 		{
// 			nbr_final[i] = nbr % size_base;
// 			nbr = nbr / size_base;
// 			i++;
// 		}
// 		len = i;
// 		while (--i >= 0)
// 			result[i] = base[nbr_final[i]];
// 		result[len + 1] = '\0';
// 	}
// 	return (result);
// }

//encrypt message into binary bitstream

char  *encrypt(char *message)
{
    char    *result;
    int     i;
    char    *temp;
    int     total_len;
    int     current_len;
	int len;

    // Calculate the total length required for the encrypted message
    total_len = 0;
    i = 0;
    while (message[i])
    {
        temp = num_to_binary(message[i]);
        total_len += ft_strlen(temp);
        free(temp);
        i++;
    }

    // Allocate memory for the result with a null terminator
    result = (char *)malloc(total_len + 9);
    if (!result)
        return NULL;

    // Encrypt the message
    i = 0;
    current_len = 0;
    while (message[i])
    {
        temp = num_to_binary(message[i]);
        len = ft_strlen(temp);
        ft_memcpy(result + current_len, temp, len);
        current_len += len;
        free(temp);
        i++;
		
    }
	// add 00000000 to the end
	ft_memcpy(result + current_len, "00000000", 9);
	current_len += 9;
    result[current_len] = '\0'; // Null-terminate the final result
    return (result);
}

void send_signals(char *message, int pid)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	while (message[i])
	{
		usleep(10000);
		// if (n <= 7)
			write(1, &message[i], 1);
		// if (n == 8)
		// {
		// 	write(1, &message[i], 1);
		// 	write(1, "\n", 1);
		// 	n = -1;
		// }
		if (message[i] == '0')
		{
			kill(pid, SIGUSR1);
		}
		else if (message[i] == '1')
		{
			kill(pid, SIGUSR2);
		}
		i++;
		n++;
	}
}

int main(int argc, char **argv)
{
	int pid;
	char *message;
	char *result;
	
	
	if (argc < 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	ft_printf("%d, %s\n", pid, message);

	result = encrypt(message);
	ft_printf("result: %s\n", result);
	send_signals(result, pid);

	return (0);
}