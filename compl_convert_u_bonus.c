/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_convert_u_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/22 12:18:35 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

static int	print_left_padded(unsigned int d, t_flags *fl);

static int	print_right_padded(unsigned int d, t_flags *fl);

static int	print_prec(unsigned int d, t_flags *fl);

static int	print_prec_width(unsigned int d, t_flags *fl, int nlen);

int	ftpr_compl_converter_u(unsigned int d, t_flags *fl)
{
	int	r;

	r = 0;
	if (!fl->minus && !fl->dot && (fl->zero || fl->space || fl->width))
		r = print_left_padded(d, fl);
	else if (fl->minus && !fl->dot)
		r = print_right_padded(d, fl);
	else if (fl->dot && (fl->prec >= fl->width))
		r = print_prec(d, fl);
	else if (fl->dot && (fl->prec < fl->width))
		r = print_prec_width(d, fl, ftpr_uintstrlen(d));
	return (r);
}

static int	print_left_padded(unsigned int d, t_flags *fl)
{
	char	*num;
	int		i;
	int		len;

	num = ftpr_utoa(d);
	len = ft_strlen(num);
	i = -1;
	i += fl->space;
	if (fl->width && fl->width > len)
		while (++i < fl->width - len)
			ft_putchar(fl->zero * '0' + !fl->zero * ' ');
	if (fl->space)
		ft_putchar(fl->plus * '+' + fl->space * ' ');
	ft_putstr(num);
	free(num);
	if (fl->width >= len)
		return (fl->width);
	return (len + fl->space);
}

// TODO: REFAC: use instrlen here? not ft_itoa and free???
static int	print_right_padded(unsigned int d, t_flags *fl)
{
	char	*num;
	int		i;
	int		len;

	num = ftpr_utoa(d);
	len = ft_strlen(num);
	i = -1;
	if (fl->space)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr(num);
	if (fl->width && fl->width > len)
		while (++i < fl->width - len)
			ft_putchar(' ');
	free(num);
	if (fl->width > len)
		return (fl->width);
	return (len);
}

static int	print_prec(unsigned int d, t_flags *fl)
{
	char	*num;
	int		i;
	int		len;

	num = ftpr_utoa(d);
	len = ft_strlen(num);
	i = -1;
	if (!d && !fl->prec)
		return (0);
	if (fl->space)
		ft_putchar(' ');
	if (fl->prec > len)
		while (++i < fl->prec - len)
			ft_putchar('0');
	ft_putstr(num);
	free(num);
	if (fl->prec >= len)
		return (fl->prec + fl->space);
	return (len + fl->space);
}

static int	print_prec_width(unsigned int d, t_flags *fl, int nlen)
{
	int		i;
	int		r;
	int		sublen;

	i = -1;
	nlen -= (!d);
	sublen = fl->prec * (nlen < fl->prec) + nlen * (nlen >= fl->prec);
	fl->width -= fl->space;
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
