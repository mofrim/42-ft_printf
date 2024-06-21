/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_simplescan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:23:09 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/20 23:25:22 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	ftp_simplescan(va_list args, char *fmt_str)
{
	int	c;
	int	r;

	r = 0;
	while (*fmt_str)
	{
		c = ftp_is_conversion(fmt_str);
		if (c >= 0)
		{
			ftp_convert_smpl(args, c, &r);
			fmt_str += 2;
		}
		// if (c < 0)
		// 	fmt_str += ftp_converter_flagged(...);
		else
		{
			ft_putchar_fd(*fmt_str, 1);
			r++;
			fmt_str++;
		}
	}
	return (r);
}
