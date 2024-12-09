/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:36:53 by girts             #+#    #+#             */
/*   Updated: 2024/07/27 16:50:15 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putunsigned_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putunsigned_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	handle_unsigned_int(va_list ap, int *i)
{
	unsigned int	arg;
	unsigned int	temp;
	int				len;

	arg = va_arg(ap, unsigned int);
	len = 1;
	temp = arg;
	ft_putunsigned_fd(arg, 1);
	while (temp > 9)
	{
		temp = temp / 10;
		len++;
	}
	*i += len;
}
