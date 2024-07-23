/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_parse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:23:55 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/23 10:44:13 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Parse args while scanning fmtstring. Returns number of printed chars. */
int	ftpr_parse_args(va_list args, const char *fmt)
{
	int	c;
	int	output;

	output = 0;
	while (*fmt)
	{
		c = ftpr_is_conversion(fmt);
		if (c == 1)
			fmt += ftpr_smpl_convert(args, fmt, &output);
		else if (c == -1)
		{
			c = ftpr_gather_flags_and_conv(args, fmt, &output);
			if (c < 0)
				return (-1);
			fmt += c;
		}
		else
		{
			ft_putchar(*fmt);
			output++;
			fmt++;
		}
	}
	return (output);
}
