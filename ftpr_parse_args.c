/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_parse_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:23:09 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/11 10:03:24 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ftpr_parse_args(va_list args, const char *fmt)
{
	int	c;
	int	r;

	r = 0;
	while (*fmt)
	{
		c = ftpr_is_conversion(fmt);
		if (c >= 0)
		{
			ftpr_convert_smpl(args, c, &r);
			fmt += 2;
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			r++;
			fmt++;
		}
	}
	return (r);
}
