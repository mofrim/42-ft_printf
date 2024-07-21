/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_convert_s_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/17 22:33:24 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

static int	print_left_padded(char *s, t_flags *fl);

static int	print_right_padded(char *s, t_flags *fl);

static int	print_prec(char *s, t_flags *fl);

static int	print_prec_width(char *s, t_flags *fl);

int	ftpr_compl_converter_s(char *s, t_flags *fl)
{
	int	r;

	r = 0;
	if (!fl->minus && !fl->dot && fl->width)
		r = print_left_padded(s, fl);
	else if (fl->minus && !fl->dot)
		r = print_right_padded(s, fl);
	else if (fl->dot)
		r = print_prec_width(s, fl);
	else
		return (ftpr_converter_s(s));
	return (r);
}

static int	print_left_padded(char *s, t_flags *fl)
{
	int		i;
	int		len;

	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	i = -1;
	if (fl->width > len)
		while (++i < fl->width - len)
			ft_putchar(' ');
	ftpr_converter_s(s);
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

static int	print_right_padded(char *s, t_flags *fl)
{
	int		i;
	int		len;

	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	i = -1;
	ftpr_converter_s(s);
	if (fl->width > len)
		while (++i < fl->width - len)
			ft_putchar(' ');
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

static int	print_prec(char *s, t_flags *fl)
{
	int		i;
	int		len;

	if (!s)
	{
		if (fl->prec >= 6)
			return (ftpr_converter_s(s));
		else
			return (0);
	}
	else
		len = ft_strlen(s);
	i = -1;
	if (fl->prec < len)
		while (++i < fl->prec)
			ft_putchar(*s++);
	else
		ftpr_converter_s(s);
	if (fl->prec < len)
		return (fl->prec);
	return (len);
}

// ("%7.7s", NULL) -> outp = ' (null)', ret = 7
// ("%.7s", NULL) -> outp = '(null)', ret = 6
// ("%.5s", NULL) -> outp = '', ret = 0
// ("%7.5s", NULL) -> outp = '       ', ret = 7
static int	print_prec_width(char *s, t_flags *fl)
{
	int		i;
	int		r;
	int		len;

	i = -1;
	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	if (!fl->minus)
	{
		while (++i < fl->width - fl->prec * ((fl->prec < len) && s != NULL) - \
len * (fl->prec >= len))
			ft_putchar(' ');
		r = print_prec(s, fl) + i;
	}
	else
	{
		r = print_prec(s, fl);
		while (++i < fl->width - r)
			ft_putchar(' ');
		r += i;
	}
	return (r);
}
