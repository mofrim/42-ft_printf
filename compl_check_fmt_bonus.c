/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_check_fmt_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:26:06 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/23 10:10:21 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
 * Checks for INVALID conversions.
 *
 * Cases for this: Conversion running off the strings end. To >INT_MAX prec or
 * width numbers.
 * 
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
