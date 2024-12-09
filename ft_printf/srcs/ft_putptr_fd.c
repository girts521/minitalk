/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:59:02 by girts             #+#    #+#             */
/*   Updated: 2024/07/27 16:44:40 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	p_digits(uintptr_t n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

static void	put_ptr(uintptr_t addr)
{
	static char	digits[] = "0123456789abcdef";

	if (addr >= 16)
		put_ptr(addr / 16);
	write(STDOUT_FILENO, &digits[addr % 16], 1);
}

int	ft_putptr_fd(void *addr)
{
	if (addr == NULL)
		return (write(STDOUT_FILENO, "(nil)", 5));
	write(STDOUT_FILENO, "0x", 2);
	put_ptr((uintptr_t)addr);
	return (p_digits((uintptr_t)addr) + 2);
}
