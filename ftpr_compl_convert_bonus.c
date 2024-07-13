/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_convert_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:09:58 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/14 01:26:35 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"
#include <stdio.h>

int	ftpr_compl_do_conv(va_list args, char conv, t_flags *flags, int *r);
int	ftpr_compl_converter_d(int d, t_flags *flags);

// TODO: EVERYTHING!!! THE WHOLE LOGIC
//
// for now: return -1 when anything goes wrong from here on down.
int	ftpr_compl_convert(va_list args, const char *fmt, int *r)
{
	t_flags	*flags;
	int	i;

	flags = init_flags();
	if (!flags)
		return (-1);
	i = 1;
	while (!is_conv_char(*(++fmt)))
	{
		if (*fmt == '+')
			flags->plus = 1;
		if (*fmt == '-')
			flags->minus = 1;
		i++;
	}
	ftpr_compl_do_conv(args, *fmt, flags, r);
	printf("\nfound conv char: %c\n", *fmt);
	(void)r;
	(void)args;
	return (i);
}

int	ftpr_compl_do_conv(va_list args, char conv, t_flags *flags, int *r)
{
	if (conv == 'd')
		*r += ftpr_compl_converter_d(va_arg(args, int), flags);

	return (0);
}

int	ftpr_compl_converter_d(int d, t_flags *flags)
{
	int		r;

	r = 0;
	if (d >= 0 && flags->plus)
	{
		ft_putchar('+');
		r = 1;
	}
	r += ftpr_converter_d(d);
	return (r);
}
