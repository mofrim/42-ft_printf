/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:43:28 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/11 10:22:37 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		printed;

	if (!fmt)
		return (-1);
	if (!*fmt)
		return (0);
	va_start(args, fmt);
	printed = ftpr_parse_args(args, fmt);
	va_end(args);
	return (printed);
}

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
