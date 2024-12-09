/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:32:27 by girts             #+#    #+#             */
/*   Updated: 2024/07/27 16:46:59 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_hex(va_list ap, int *i)
{
	unsigned int	hex_arg;
	unsigned int	temp;
	int				len;

	hex_arg = va_arg(ap, unsigned int);
	len = 1;
	temp = hex_arg;
	ft_puthex_fd(hex_arg, 1);
	while (temp >= 16)
	{
		temp = temp / 16;
		len++;
	}
	*i += len;
}
