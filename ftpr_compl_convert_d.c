/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_convert_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:55:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/15 01:54:16 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

static int	print_left_padded(int d, t_flags *fl);

int	ftpr_compl_converter_d(int d, t_flags *fl)
{
	int	r;

	r = 0;
	if (!fl->minus)
		r = print_left_padded(d, fl);
	return (r);
}

static int	print_left_padded(int d, t_flags *fl)
{
	char	*num;
	int		i;
	int		len;

	num = ft_itoa(d);
	len = ft_strlen(num);
	i = -1;
	if (fl->zero && fl->width && fl->width > len)
		while(++i < fl->width - len)
			ft_putchar('0');
	ft_putstr(num);
	free(num);
	if (fl->width >= len)
		return (fl->width);
	return (len);
}

// int	ftpr_compl_converter_d(int d, t_flags *flags)
// {
//
// 	int	c;
//
// 	c = 0;
// 	if (d >= 0 && flags->plus)
// 	{
// 		ft_putchar('+');
// 		c = 1;
// 	}
// 	c += ftpr_converter_d(d);
// 	return (c);
// }
