/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_convert_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:23:55 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/12 11:29:12 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// check if substr at `s` is a simple conv or flagged conv
// Return Values:
// 		0	no conv
// 		1	only simple conv needed
// 		-1	complex conversion
int	ftpr_is_conversion(const char *s)
{
	if (ftpr_is_smpl_conv(s))
		return (1);
	if (*s == '%' && ftpr_is_compl_conv(s))
		return (-1);
	return (0);
}

// for first debugging: print detected compl_conv
int	ftpr_convert_compl(va_list args, const char *fmt, int *r)
{
	(void)r;
	(void)args;
	(void)fmt; 

	return(0);
}

int	ftpr_parse_args(va_list args, const char *fmt)
{
	int	c;
	int	r;

	r = 0;
	while (*fmt)
	{
		c = ftpr_is_conversion(fmt);
		if (c == 1)
		{
			ftpr_convert_smpl(args, fmt, &r);
			fmt += 2;
		}
		else if (c == -1)
			fmt += ftpr_convert_compl(args, fmt, &r);
		else
		{
			ft_putchar_fd(*fmt, 1);
			r++;
			fmt++;
		}
	}
	return (r);
}
