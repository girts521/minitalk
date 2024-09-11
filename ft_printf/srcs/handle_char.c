/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:28:24 by girts             #+#    #+#             */
/*   Updated: 2024/07/21 14:08:15 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_char(va_list ap, int *i)
{
	char	char_arg;

	char_arg = (char)va_arg(ap, int);
	write(1, &char_arg, 1);
	*i += 1;
}
