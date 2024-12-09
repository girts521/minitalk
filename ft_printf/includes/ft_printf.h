/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:05:42 by girts521          #+#    #+#             */
/*   Updated: 2024/07/27 16:51:18 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

typedef void	(*t_format_handler)(va_list ap, int *i);

typedef struct t_format_specifier
{
	char				specifier;
	t_format_handler	handler;
}	t_format_specifier;

int		ft_printf(const char *str, ...);
int		ft_putptr_fd(void *addr);
int		count_hexdigits(long long int n);
void	ft_puthex_fd(unsigned int n, int fd);
void	ft_puthex_upper_fd(unsigned int n, int fd);
void	handle_char(va_list ap, int *i);
void	handle_hex_upper(va_list ap, int *i);
void	handle_hex(va_list ap, int *i);
void	handle_int(va_list ap, int *i);
void	handle_pointer(va_list ap, int *i);
void	handle_string(va_list ap, int *i);
void	handle_unsigned_int(va_list ap, int *i);

#endif