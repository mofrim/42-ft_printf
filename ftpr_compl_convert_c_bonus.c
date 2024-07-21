/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_convert_c_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/21 12:26:37 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_right_padded(int c, t_flags *fl);

static int	print_left_padded(int c, t_flags *fl);

/**
 * Width flag aware conversion of char.
 *
 * @param c The char to be put out
 * @param fl The t_flags struct with all the flags requested
 *
 * @return Returns number of printed chars
 */
int	ftpr_compl_converter_c(int c, t_flags *fl)
{
	int	r;

	r = 0;
	if (fl->minus)
		r = print_right_padded(c, fl);
	else if (!fl->minus)
		r = print_left_padded(c, fl);
	return (r);
}

static int	print_right_padded(int c, t_flags *fl)
{
	int		i;

	i = -1;
	ft_putchar(c);
	if (fl->width)
		while (++i < fl->width - 1)
			ft_putchar(' ');
	if (fl->width)
		return (fl->width);
	return (1);
}

static int	print_left_padded(int c, t_flags *fl)
{
	int		i;

	i = -1;
	while (++i < fl->width - 1)
		ft_putchar(' ');
	ft_putchar(c);
	if (fl->width)
		return (fl->width);
	return (1);
}
