/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:43:50 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/12 13:44:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

// cspdiuxX%
int	is_conv_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	is_flag_char(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '#' || c == '0')
		return (1);
	return (0);
}

int	is_valid_flagconv_char(char c)
{
	if (is_flag_char(c) || is_conv_char(c) || ft_isdigit(c) || c == '.')
		return (1);
	return (0);
}
