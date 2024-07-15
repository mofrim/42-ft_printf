/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_do_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:50:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/15 14:12:42 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ftpr_compl_do_conv(va_list args, char conv, t_flags *flags, int *output)
{
	if (conv == 'd' || conv == 'i')
		*output += ftpr_compl_converter_d(va_arg(args, int), flags);
	if (conv == 'u')
		*output += ftpr_compl_converter_d(va_arg(args, int), flags);
	return (0);
}
