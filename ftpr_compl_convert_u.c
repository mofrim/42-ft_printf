/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_convert_u.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/15 16:34:35 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

static int	print_zero_left_padded(unsigned int d, t_flags *fl);

static int	print_right_padded(unsigned int d, t_flags *fl);

static int	print_prec(unsigned int d, t_flags *fl);

static int	print_prec_width(unsigned int d, t_flags *fl);

int	ftpr_compl_converter_u(unsigned int d, t_flags *fl)
{
	int	r;

	r = 0;
	if (!fl->minus && !fl->dot && (fl->zero || fl->plus || fl->space || fl->width))
		r = print_zero_left_padded(d, fl);
	else if (fl->minus && !fl->dot)
		r = print_right_padded(d, fl);
	else if (fl->dot && (fl->prec >= fl->width))
		r = print_prec(d, fl);
	else if (fl->dot && (fl->prec < fl->width))
		r = print_prec_width(d, fl);
	return (r);
}

static int	print_zero_left_padded(unsigned int d, t_flags *fl)
{
	char	*num;
	int		i;
	int		len;

	num = ft_itoa(d);
	len = ft_strlen(num);
	i = -1;
	if (fl->plus || fl->space)
		i++;
	if (fl->width && fl->width > len)
		while (++i < fl->width - len)
			ft_putchar(fl->zero * '0' + !fl->zero * ' ');
	ft_putchar(fl->plus * '+' + fl->space * ' ');
	ft_putstr(num);
	free(num);
	if (fl->width >= len)
		return (fl->width);
	return (len + (fl->plus || fl->space));
}

static int	print_right_padded(unsigned int d, t_flags *fl)
{
	char	*num;
	int		i;
	int		len;

	num = ft_itoa(d);
	len = ft_strlen(num);
	i = -1;
	if (fl->plus || fl->space)
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
	return (len);
}

static int	print_prec(unsigned int d, t_flags *fl)
{
	char	*num;
	int		i;
	int		len;

	num = ft_itoa(d);
	len = ft_strlen(num);
	i = -1;
	if (fl->plus || fl->space)
		ft_putchar(fl->plus * '+' + fl->space * ' ');
	if (fl->prec > len)
		while (++i < fl->prec - len)
			ft_putchar('0');
	ft_putstr(num);
	free(num);
	if (fl->prec >= len)
		return (fl->prec + (fl->plus || fl->space) );
	return (len + (fl->plus || fl->space));
}

static int	print_prec_width(unsigned int d, t_flags *fl)
{
	int		i;
	int		r;

	i = -1;
	if (fl->plus || fl->space)
		fl->width--;
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
