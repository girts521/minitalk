/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:33:03 by girts             #+#    #+#             */
/*   Updated: 2024/07/27 16:47:36 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_int(va_list ap, int *i)
{
	long int	long_arg;
	long int	temp;
	int			len;

	long_arg = va_arg(ap, int);
	len = 1;
	temp = 0;
	if (long_arg > INT_MAX)
		return ;
	else if (long_arg < INT_MIN)
		return ;
	else
		ft_putnbr_fd((int)long_arg, 1);
	temp = (int)long_arg;
	if (temp < 0)
	{
		len++;
		temp = -temp;
	}
	while (temp > 9)
	{
		temp = temp / 10;
		len++;
	}
	*i += len;
}
