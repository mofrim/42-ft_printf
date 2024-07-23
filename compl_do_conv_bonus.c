/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_do_conv_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:50:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/23 10:39:19 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	percent(void);

/*
 * Finally really do the conversion.
 *
 * Does the conversion specified in param char conv. The number of printed chars
 * is saved in param int output which will finally be returned from
 * ftpr_parse_args to main ft_printf func.
 *
 */
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

/* The sinplest conv ever.
 *
 * Still we need this here because there might be any agglomeration of valid
 * flags in between the first % and the final one.
 *
 */
static int	percent(void)
{
	ft_putchar('%');
	return (1);
}
