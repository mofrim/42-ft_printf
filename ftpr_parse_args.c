/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_parse_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:23:09 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/22 11:21:41 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

// TODO: maybe init flags right here
//
// t_flags flags;
//
// init_flags(flags);
//
// TODO: refactor: there will be only one conversion function in the
// end. maybe... or just pull through with my split approach. results in
// more code to be written but maybe less brain to be used.
//
// if (c < 0)
// 	fmt_str += ftpr_convert_flag(flags, args, c, &r);
int	ftpr_parse_args(va_list args, char *fmt_str)
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
		else
		{
			ft_putchar_fd(*fmt_str, 1);
			r++;
			fmt_str++;
		}
	}
	return (r);
}
