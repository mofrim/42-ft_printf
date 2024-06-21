/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_simplescan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:23:09 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/21 11:52:35 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpr_printf.h"
#include "libft/libft.h"

int	ftpr_simplescan(va_list args, char *fmt_str)
{
	int	c;
	int	r;

	r = 0;
	while (*fmt_str)
	{
		c = ftpr_is_conversion(fmt_str);
		if (c >= 0)
		{
			ftpr_convert_smpl(args, c, &r);
			fmt_str += 2;
		}
		// if (c < 0)
		// 	fmt_str += ftpr_converter_flagged(...);
		else
		{
			ft_putchar_fd(*fmt_str, 1);
			r++;
			fmt_str++;
		}
	}
	return (r);
}
