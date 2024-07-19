/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_convert_x_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/19 23:43:33 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static int	print_left_padded(unsigned int i, t_flags *fl, int c);

static int	print_right_padded(unsigned int i, t_flags *fl, int c);

static int	print_prec(unsigned int i, t_flags *fl, int c);

static int	print_prec_width(unsigned int i, t_flags *fl, int c);

int	ftpr_compl_converter_x(unsigned int i, t_flags *fl, int c)
{
	int	r;

	r = 0;
	if (!fl->minus && !fl->dot && fl->width)
		r = print_left_padded(i, fl, c);
	else if (fl->minus && !fl->dot)
		r = print_right_padded(i, fl, c);
	else if (fl->dot)
		r = print_prec_width(i, fl, c);
	else
	{
		ftpr_print_zerox(fl->hash, c, i);
		if (c == 'x')
			return (ftpr_converter_x(i) + 2 * (i != 0) * fl->hash);
		else
			return (ftpr_converter_xupper(i) + 2 * (i != 0) * fl->hash);
	}
	return (r);
}

static int	print_left_padded(unsigned int i, t_flags *fl, int c)
{
	int		k;
	int		len;

	len = ftpr_hex_digits(i) + fl->hash * 2;
	k = -1;
	if (fl->width > len)
		while (++k < fl->width - len)
			ft_putchar(!fl->zero * ' ' + fl->zero * '0');
	ftpr_print_zerox(fl->hash, c, i);
	if (c == 'x')
		ftpr_converter_x(i);
	else
		ftpr_converter_xupper(i);
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

static int	print_right_padded(unsigned int i, t_flags *fl, int c)
{
	int		k;
	int		len;

	len = ftpr_hex_digits(i) + fl->hash * 2;
	k = -1;
	ftpr_print_zerox(fl->hash, c, i);
	if (c == 'x')
		ftpr_converter_x(i);
	else
		ftpr_converter_xupper(i);
	if (fl->width > len)
		while (++k < fl->width - len)
			ft_putchar(' ');
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

static int	print_prec(unsigned int i, t_flags *fl, int c)
{
	int		k;
	int		len;

	len = ftpr_hex_digits(i);
	k = -1;
	if (i == 0 && !fl->prec)
		return (0);
	if ((fl->prec < len) && (c == 'x'))
		ftpr_converter_x(i);
	else if ((fl->prec < len) && (c == 'X'))
		ftpr_converter_xupper(i);
	else
	{
		while (++k < fl->prec - len)
			ft_putchar('0');
		if (c == 'x')
			ftpr_converter_x(i);
		else
			ftpr_converter_xupper(i);
	}
	if (fl->prec < len)
		return (len);
	return (fl->prec);
}

static int	print_prec_width(unsigned int i, t_flags *fl, int c)
{
	int		k;
	int		r;
	int		len;

	k = -1;
	len = (i != 0 || fl->prec) * (ftpr_hex_digits(i) + fl->hash * 2);
	if (!fl->minus)
	{
		while (++k < fl->width - (fl->prec + (i != 0) * fl->hash * 2) \
* (fl->prec >= len) - len * (fl->prec < len))
			ft_putchar(' ');
		ftpr_print_zerox(fl->hash, c, i);
		r = print_prec(i, fl, c) + k;
		r += ((i != 0) * 2 * fl->hash * (fl->width < len));
	}
	else
	{
		ftpr_print_zerox(fl->hash, c, i);
		r = print_prec(i, fl, c);
		while (++k < fl->width - r)
			ft_putchar(' ');
		r += k;
	}
	return (r);
}
