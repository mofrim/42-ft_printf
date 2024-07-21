/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_do_conv_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:50:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/19 23:46:43 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	percent(void);

int	ftpr_compl_do_conv(va_list args, char conv, t_flags *flags, int *output)
{
	if (conv == '%')
		*output += percent();
	else if (conv == 'd' || conv == 'i')
		*output += ftpr_compl_converter_d(va_arg(args, int), flags);
	else if (conv == 'u')
		*output += ftpr_compl_converter_u(va_arg(args, unsigned int), flags);
	else if (conv == 'c')
		*output += ftpr_compl_converter_c(va_arg(args, int), flags);
	else if (conv == 's')
		*output += ftpr_compl_converter_s(va_arg(args, char *), flags);
	else if (conv == 'p')
		*output += ftpr_compl_converter_p(va_arg(args, unsigned long), flags);
	else if (conv == 'x' || conv == 'X')
		*output += ftpr_compl_converter_x(va_arg(args, unsigned int),
				flags, conv);
	return (0);
}

static int	percent(void)
{
	ft_putchar('%');
	return (1);
}
