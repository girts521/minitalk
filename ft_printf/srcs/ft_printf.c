/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:35:38 by girts521          #+#    #+#             */
/*   Updated: 2024/07/27 16:38:07 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	initialize_table(t_format_specifier *format_table)
{
	format_table[0].specifier = 'c';
	format_table[0].handler = handle_char;
	format_table[1].specifier = 's';
	format_table[1].handler = handle_string;
	format_table[2].specifier = 'd';
	format_table[2].handler = handle_int;
	format_table[3].specifier = 'i';
	format_table[3].handler = handle_int;
	format_table[4].specifier = 'u';
	format_table[4].handler = handle_unsigned_int;
	format_table[5].specifier = 'p';
	format_table[5].handler = handle_pointer;
	format_table[6].specifier = 'x';
	format_table[6].handler = handle_hex;
	format_table[7].specifier = 'X';
	format_table[7].handler = handle_hex_upper;
}

static int	handle_argument(char conversion, va_list *ap, \
							t_format_specifier *format_table, int *len)
{
	size_t	i;

	i = 0;
	while (i <= 8)
	{
		if (format_table[i].specifier == conversion)
		{
			format_table[i].handler(*ap, len);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	process_format_string(const char *str, va_list *ap, \
									t_format_specifier *format_table)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str++, 1);
			i++;
			continue ;
		}
		str++;
		if (!*str)
			return (0);
		if (*str == '%')
		{
			ft_putchar_fd('%', 1);
			i++;
		}
		else if (!handle_argument(*str, ap, format_table, &i))
			return (0);
		str++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list				ap;
	t_format_specifier	*format_table;
	int					result;

	format_table = malloc(9 * sizeof(t_format_specifier));
	if (!format_table)
	{
		ft_putstr_fd("Memory allocation failed\n", 2);
		return (0);
	}
	initialize_table(format_table);
	va_start(ap, str);
	result = process_format_string(str, &ap, format_table);
	va_end(ap);
	free(format_table);
	return (result);
}
