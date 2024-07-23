/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_convert_x_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/23 17:50:55 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

static int	print_left_padded(unsigned int i, t_flags *fl, int c);

static int	print_right_padded(unsigned int i, t_flags *fl, int c);

static int	print_prec(unsigned int i, t_flags *fl, int c);

static int	print_prec_width(unsigned int i, t_flags *fl, int c);

/* Convert to hex with "-. 0" flags. */
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
			return (ftpr_converter_x(i, 0) + 2 * (i != 0) * fl->hash);
		else
			return (ftpr_converter_x(i, 1) + 2 * (i != 0) * fl->hash);
	}
	return (r);
}

/* Helper function. Print left padded. */
static int	print_left_padded(unsigned int i, t_flags *fl, int c)
{
	int		k;
	int		len;

	len = (i != 0) * (ftpr_hex_digits(i) + fl->hash * 2) + (!i);
	k = -1;
	if (fl->zero && fl->hash)
		ftpr_print_zerox(fl->hash, c, i);
	if (fl->width > len)
		while (++k < fl->width - len)
			ft_putchar(!fl->zero * ' ' + fl->zero * '0');
	if (!(fl->zero && fl->hash))
		ftpr_print_zerox(fl->hash, c, i);
	if (c == 'x')
		ftpr_converter_x(i, 0);
	else
		ftpr_converter_x(i, 1);
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

/* Helper function. Print right padded. */
static int	print_right_padded(unsigned int i, t_flags *fl, int c)
{
	int		k;
	int		len;

	len = ftpr_hex_digits(i) + (i != 0) * fl->hash * 2;
	k = -1;
	ftpr_print_zerox(fl->hash, c, i);
	if (c == 'x')
		ftpr_converter_x(i, 0);
	else
		ftpr_converter_x(i, 1);
	if (fl->width > len)
		while (++k < fl->width - len)
			ft_putchar(' ');
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

/* Helper function. Print with precission. */
static int	print_prec(unsigned int i, t_flags *fl, int c)
{
	int		k;
	int		len;

	len = ftpr_hex_digits(i);
	k = -1;
	if (i == 0 && !fl->prec)
		return (0);
	if ((fl->prec < len) && (c == 'x'))
		ftpr_converter_x(i, 0);
	else if ((fl->prec < len) && (c == 'X'))
		ftpr_converter_x(i, 1);
	else
	{
		while (++k < fl->prec - len)
			ft_putchar('0');
		if (c == 'x')
			ftpr_converter_x(i, 0);
		else
			ftpr_converter_x(i, 1);
	}
	if (fl->prec < len)
		return (len);
	return (fl->prec);
}

/* Helper function. Print with precission & width. */
static int	print_prec_width(unsigned int i, t_flags *fl, int c)
{
	int		k;
	int		r;
	int		len;

	k = -1;
	len = (!i) * fl->prec + (i != 0) * ftpr_hex_digits(i);
	if (!fl->minus)
	{
		// fails!?
		while (++k < fl->width - (fl->prec + (i != 1) * fl->hash * 2) \
			* (fl->prec >= len) - (len + (i != 0) * fl->hash * 2) \
			* (fl->prec < len))
			ft_putchar(' ');
		ftpr_print_zerox(fl->hash, c, i);
		r = print_prec(i, fl, c) + k;
		r += (i != 0) * 2 * fl->hash;
	}
	else
	{
		ftpr_print_zerox(fl->hash, c, i);
		r = print_prec(i, fl, c);
		while (++k < fl->width - (r + fl->hash * 2 * (i != 0)))
			ft_putchar(' ');
		r += k + (i != 0) * (fl->hash * 2);
	}
	return (r);
}
