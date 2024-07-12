/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_is_compl_conv_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:45:16 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/12 10:36:46 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

// ::The Rules::
//
// i)  	 a '%' can be followed by any mix of '+- 0#'
// ii)   BUT after the first number != 0 OR a '.' there can only be
// iii)	 more numbers (actually until UINT_MAX)
// iv) 	 NO 2 DOTS! ONLY ONE DOT ALLOWED!!
// v) 	 if the first thing was a number, there can be a dot followed by another
//     	 number, or simply a dot
// vi)	 after a '.' only a number and the conv_spec are allowed
// vii)	 the '%' conversion can have any valid combination of flags (including
//     	 width and prec) in between first % and final %. the final % can be 
//     	 followed by valid conv_char, it still will be printed like %%.
// viii) a '0' after a '.' is ingored but valid
// 
// NOTE: INVALID sequences lead to parts of or the whole sequence being printed.
// but there are lot of combinations where the ignored or doubled stuff is not
// printed even though it has no effect.
//
// NOTE: *s is pointing to the first '%' in the conversion string of interest.
// so the loop starts looking at the first char after the %
//
// if we reach end of string without having found any conv_char this is a printf
// error and we shall return -1!
// TODO: handle this!
int	ftpr_is_compl_conv(const char *s)
{
	int	num;
	int	dot;

	num = 0;
	dot = 0;
	while(*s++)
	{
		if (!is_valid_flagconv_char(*s))
			return (0);
		// here is the problem... because 0 is a flag char
		if (is_flag_char(*s) && *s != '0' && (num || dot) ) 
			return (0);
		if (*s == '.' && dot)
			return (0);
		if (is_conv_char(*s))
			return (1);
		if (ft_isdigit(*s) && !num && *s != '0')
			num = 1;
		if (*s == '.')
			dot = 1;
	}
	return (0);
}

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
ftpr_iscom
