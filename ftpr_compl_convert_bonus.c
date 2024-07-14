/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_convert_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:09:58 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/14 02:01:09 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdio.h>

int	ftpr_compl_do_conv(va_list args, char conv, t_flags *flags, int *output);
int	ftpr_compl_converter_d(int d, t_flags *flags);

// TODO: EVERYTHING!!! THE WHOLE LOGIC
//
// for now: return -1 when anything goes wrong from here on down.
int	ftpr_compl_convert(va_list args, const char *fmt, int *output)
{
	t_flags	*flags;
	int		conv_seq_len;

	flags = init_flags();
	conv_seq_len = 0;
	if (!flags)
		return (-1);
	while (!is_conv_char(*(++fmt)))
	{
		// TODO:
		// - move all of this to seperate function
		// - make up handling for width and prec
		// - is there anything independent?
		if (*fmt == '+')
			flags->plus = 1;
		if (*fmt == '-')
			flags->minus = 1;
		if (*fmt == '0' && !flags->width && !flags->dot)
			flags->zero = 1;
		conv_seq_len++;
	}
	ftpr_compl_do_conv(args, *fmt, flags, output);
	return (conv_seq_len + 2); // add 2 because of % and conv_char
}

int	ftpr_compl_do_conv(va_list args, char conv, t_flags *flags, int *output)
{
	if (conv == 'd')
		*output += ftpr_compl_converter_d(va_arg(args, int), flags);
	return (0);
}

int	ftpr_compl_converter_d(int d, t_flags *flags)
{
	int	c;

	c = 0;
	if (d >= 0 && flags->plus)
	{
		ft_putchar('+');
		c = 1;
	}
	c += ftpr_converter_d(d);
	return (c);
}
