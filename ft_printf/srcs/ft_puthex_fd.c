/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:06:51 by girts             #+#    #+#             */
/*   Updated: 2024/07/27 16:40:14 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_puthex_fd(unsigned int n, int fd)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex_fd(n / 16, fd);
		ft_putchar_fd(hex_digits[n % 16], fd);
	}
	else
		ft_putchar_fd(hex_digits[n], fd);
}
