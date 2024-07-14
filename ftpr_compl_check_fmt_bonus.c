/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_check_fmt_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:26:06 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/14 16:50:12 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// checks for INVALID conversions
//
// this is necessary in case of incomplete conversions present in fmt_string
// nothing should be printed at all and -1 be be returned by ft_printf.
//
int	ftpr_check_fmt(const char *fmt)
{
	while (*fmt)
	{
		if (*fmt == '%')
			if (ftpr_compl_is_conv(fmt) == -1)
				return (0);
		fmt++;
	}
	return (1);
}
