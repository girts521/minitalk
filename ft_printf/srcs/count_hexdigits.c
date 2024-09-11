/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_hexdigits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:04:02 by girts             #+#    #+#             */
/*   Updated: 2024/06/25 18:26:32 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	count_hexdigits(long long int n)
{
	if (n == 0)
		return (0);
	if (n < 0)
		n = -n;
	return (1 + count_hexdigits(n / 16));
}
