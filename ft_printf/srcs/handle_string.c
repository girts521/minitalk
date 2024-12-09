/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:36:09 by girts             #+#    #+#             */
/*   Updated: 2024/07/21 14:39:08 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	handle_string(va_list ap, int *i)
{
	char	*str_arg;
	int		len;

	str_arg = va_arg(ap, char *);
	if (str_arg == NULL)
		str_arg = "(null)";
	len = ft_strlen(str_arg);
	if (len == 0)
		return ;
	write(1, str_arg, len);
	*i = *i + ft_strlen(str_arg);
}
