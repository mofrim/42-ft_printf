/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_convert_d_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/23 10:33:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

static int	print_left_padded(int d, t_flags *fl);

static int	print_right_padded(int d, t_flags *fl);

static int	print_prec(int d, t_flags *fl);

static int	print_prec_width(int d, t_flags *fl, int nlen);

/* Convert integer with flags. */
int	ftpr_compl_converter_d(int d, t_flags *fl)
{
	int	r;

	r = 0;
	if (!fl->minus && !fl->dot && (fl->zero || fl->plus || fl->space \
|| fl->width))
		r = print_left_padded(d, fl);
	else if (fl->minus && !fl->dot)
		r = print_right_padded(d, fl);
	else if (fl->dot && (fl->prec >= fl->width))
		r = print_prec(d, fl);
	else if (fl->dot && (fl->prec < fl->width))
		r = print_prec_width(d, fl, ftpr_intstrlen(d));
	return (r);
}

/* Helper function. Print left padded. */
static int	print_left_padded(int d, t_flags *fl)
{
	char	*num;
	int		i;
	int		len;

	num = ft_itoa(d);
	len = ft_strlen(num);
	i = -1;
	if (d < 0 && fl->zero)
		ft_putchar('-');
	if (d >= 0 && (fl->plus || fl->space) && fl->zero)
		ft_putchar(fl->plus * '+' + fl->space * ' ');
	if (fl->width > len)
		while (++i < fl->width - len - (d >= 0 && (fl->plus || fl->space)))
			ft_putchar(fl->zero * '0' + !fl->zero * ' ');
	if (d >= 0 && (fl->plus || fl->space) && !fl->zero)
		ft_putchar(fl->plus * '+' + fl->space * ' ');
	if (d < 0)
		ft_putstr(num + 1 * fl->zero);
	else
		ft_putstr(num);
	free(num);
	if (fl->width >= len + ((fl->plus || fl->space) && (d >= 0)))
		return (fl->width);
	return (len + ((fl->plus || fl->space) && (d >= 0)));
}

/* Helper function. Print right padded. */
static int	print_right_padded(int d, t_flags *fl)
{
	char	*num;
	int		i;
	int		len;

	num = ft_itoa(d);
	len = ft_strlen(num);
	i = -1;
	if (d >= 0 && (fl->plus || fl->space))
	{
		ft_putchar(fl->plus * '+' + fl->space * ' ');
		i++;
	}
	ft_putstr(num);
	if (fl->width && fl->width > len)
		while (++i < fl->width - len)
			ft_putchar(' ');
	free(num);
	if (fl->width > len)
		return (fl->width);
	return (len + ((fl->space || fl->plus) && (d >= 0)));
}

/* Helper function. Print with precission. */
static int	print_prec(int d, t_flags *fl)
{
	char	*num;
	int		i;
	int		len;

	num = ft_itoa(d);
	len = ft_strlen(num);
	i = -1;
	if (!d && !fl->prec)
		return (0);
	if (d < 0)
		ft_putchar('-');
	if (d >= 0 && (fl->plus || fl->space))
		ft_putchar(fl->plus * '+' + fl->space * ' ');
	if (fl->prec > len - (d < 0))
		while (++i < fl->prec - len + (d < 0))
			ft_putchar('0');
	if (d < 0)
		ft_putstr(num + 1);
	else
		ft_putstr(num);
	free(num);
	if (fl->prec >= len)
		return (fl->prec + ((fl->plus || fl->space) && (d >= 0)) + (d < 0));
	return (len + ((fl->plus || fl->space) && (d >= 0)));
}

/* Helper function. Print with precission & width. */
static int	print_prec_width(int d, t_flags *fl, int nlen)
{
	int		i;
	int		r;
	int		sublen;

	i = -1;
	nlen -= (d < 0) + (!d);
	sublen = fl->prec * (nlen < fl->prec) + nlen * (nlen >= fl->prec);
	if (d < 0 || fl->plus || fl->space)
		fl->width--;
	if (!fl->minus)
	{
		while (++i < fl->width - sublen)
			ft_putchar(' ');
		r = print_prec(d, fl) + i;
	}
	else
	{
		r = print_prec(d, fl);
		while (++i < fl->width - sublen)
			ft_putchar(' ');
		r += i;
	}
	return (r);
}
