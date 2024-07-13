/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_is_conv_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:45:16 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/13 13:10:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"
//
// check if substr at `s` is a simple conv or flagged conv
// Return Values:
// 		0	no conv
// 		1	only simple conv needed
// 		-1	complex conversion
// 		-42	evaluation of conversion reached end of string like in "%+-00-"
int	ftpr_is_conversion(const char *s)
{
	if (ftpr_smpl_is_conv(s))
		return (1);
	if (*s == '%' && ftpr_compl_is_conv(s) == 1)
		return (-1);
	if (*s == '%' && ftpr_compl_is_conv(s) == -1)
		return (-42);
	return (0);
}

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
// ix)	 IF there is a invalid sequence at the end of fmtstring nothing will
// 		 be printed, not even preceeding valid characters or conversions and -1 has to
// 		 be returned! TODO: handle this (how?)!
// 
// NOTE: INVALID sequences lead to parts of or the whole sequence being printed.
// but there are lot of combinations where the ignored or doubled stuff is not
// printed even though it has no effect.
//
// NOTE: *s is pointing to the first '%' in the conversion string of interest.
// so the loop starts looking at the first char after the %
//
// if we reach end of string without having found any conv_char this is a printf
// error and we shall return -1! without printing anything!!! see rule ix)
// TODO: handle this!
// maybe by a function, say, scan_for_incomplete_convs() that in advance checks
// the formatstring for ftpr_is_compl_conv() returning -42
// -> i think logically this function should reside in ftpr_compl_parse.c
int	ftpr_compl_is_conv(const char *s)
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
	return (-1);
}

// for first debugging: print detected compl_conv
int	ftpr_compl_convert(va_list args, const char *fmt, int *r)
{
	(void)r;
	(void)args;
	(void)fmt; 

	return(0);
}
