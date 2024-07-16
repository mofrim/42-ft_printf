/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_convert_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/16 20:36:46 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

static int	print_zero_left_padded(int d, t_flags *fl);

static int	print_right_padded(int d, t_flags *fl);

static int	print_prec(int d, t_flags *fl);

static int	print_prec_width(int d, t_flags *fl);

int	ftpr_compl_converter_c(int d, t_flags *fl)
{
	int	r;

	r = 0;
	if (!fl->minus && !fl->dot && (fl->zero || fl->space || fl->width))
		r = print_zero_left_padded(d, fl);
	else if (fl->minus && !fl->dot)
		r = print_right_padded(d, fl);
	else if (fl->dot && (fl->prec >= fl->width))
		r = print_prec(d, fl);
	else if (fl->dot && (fl->prec < fl->width))
		r = print_prec_width(d, fl);
	return (r);
}

static int	print_zero_left_padded(int d, t_flags *fl)
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

static int	print_right_padded(int d, t_flags *fl)
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

static int	print_prec(int d, t_flags *fl)
{
	char	*num;
	int		i;
	int		len;

	num = ftpr_utoa(d);
	len = ft_strlen(num);
	i = -1;
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

static int	print_prec_width(int d, t_flags *fl)
{
	int		i;
	int		r;

	i = -1;
	fl->width -= fl->space;
	if (!fl->minus)
	{
		while (++i < fl->width - fl->prec)
			ft_putchar(' ');
		r = print_prec(d, fl) + i;
	}
	else
	{
		r = print_prec(d, fl);
		while (++i < fl->width - fl->prec)
			ft_putchar(' ');
		r += i;
	}
	return (r);
}
