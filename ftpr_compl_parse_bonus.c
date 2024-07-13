/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_parse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:23:55 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/12 13:48:35 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"


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
		else if (c == -42)
			return (-1);
		else
		{
			ft_putchar_fd(*fmt, 1);
			r++;
			fmt++;
		}
	}
	return (r);
}
