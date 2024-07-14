/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:43:50 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/14 16:31:32 by fmaurer          ###   ########.fr       */
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

// well, i need an atoui which detects a possible overflow. input is a
// tring of digits representing a non-negtive number
long	ftpr_compl_atol(const char *s)
{
	long	num;

	num = 0;
	while (ft_isdigit(*s))
	{
		num = num * 10 + *s++ - '0';
		if (num > INT_MAX)
			return (-1);
	}
	return (num);
}
