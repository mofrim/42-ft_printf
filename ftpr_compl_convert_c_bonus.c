/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_convert_c_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/21 08:08:38 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_right_padded(int d, t_flags *fl);

static int	print_left_padded(int d, t_flags *fl);

int	ftpr_compl_converter_c(int d, t_flags *fl)
{
	int	r;

	r = 0;
	if (fl->minus)
		r = print_right_padded(d, fl);
	else if (!fl->minus)
		r = print_left_padded(d, fl);
	return (r);
}

static int	print_right_padded(int d, t_flags *fl)
{
	int		i;

	i = -1;
	ft_putchar(d);
	if (fl->width)
		while (++i < fl->width - 1)
			ft_putchar(' ');
	if (fl->width)
		return (fl->width);
	return (1);
}

static int	print_left_padded(int d, t_flags *fl)
{
	int		i;

	i = -1;
	while (++i < fl->width - 1)
		ft_putchar(' ');
	ft_putchar(d);
	if (fl->width)
		return (fl->width);
	return (1);
}
