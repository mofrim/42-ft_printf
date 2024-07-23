/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_check_fmt_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:26:06 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/23 08:29:44 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/**
 * Checks for INVALID conversions.
 *
 * this is necessary in case of incomplete conversions present in fmt_string
 * nothing should be printed at all and -1 be be returned by ft_printf.
 */
int	ftpr_check_fmt(const char *fmt)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (ftpr_compl_isconv(fmt) == -1)
				return (0);
			while (ftpr_isflagconv(*(++fmt)) != 1)
				;
		}
		fmt++;
	}
	return (1);
}
