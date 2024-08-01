/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:52:03 by fmaurer           #+#    #+#             */
/*   Updated: 2024/08/01 14:51:25 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "ft_printf_bonus.h"
#else 
# include "ft_printf.h"
#endif

/* Take this if we are not doing the bonus part. */
#ifndef BONUS

/* Wrapper func for smpl_isconv. Only there for code seperation. */
int	ftpr_is_conversion(const char *s)
{
	if (ftpr_smpl_isconv(s))
		return (1);
	return (0);
}

#endif

/* Is current conv string a smpl conv? */
int	ftpr_smpl_isconv(const char *s)
{
	if (!ft_strncmp(s, "%c", 2) || !ft_strncmp(s, "%s", 2) || \
		!ft_strncmp(s, "%p", 2) || !ft_strncmp(s, "%d", 2) || \
		!ft_strncmp(s, "%i", 2) || !ft_strncmp(s, "%u", 2) || \
		!ft_strncmp(s, "%x", 2) || !ft_strncmp(s, "%X", 2) || \
		!ft_strncmp(s, "%%", 2))
		return (1);
	return (0);
}

/* Calls the actual conversion functions. In smpl case always returns 2. */
int	ftpr_smpl_convert(va_list args, const char *s, int *r)
{
	if (!ft_strncmp(s, "%c", 2))
		*r += ftpr_converter_c(va_arg(args, int));
	if (!ft_strncmp(s, "%s", 2))
		*r += ftpr_converter_s(va_arg(args, char *));
	if (!ft_strncmp(s, "%p", 2))
		*r += ftpr_converter_p(va_arg(args, unsigned long));
	if (!ft_strncmp(s, "%d", 2))
		*r += ftpr_converter_d(va_arg(args, int));
	if (!ft_strncmp(s, "%i", 2))
		*r += ftpr_converter_d(va_arg(args, int));
	if (!ft_strncmp(s, "%u", 2))
		*r += ftpr_converter_u(va_arg(args, unsigned int));
	if (!ft_strncmp(s, "%x", 2))
		*r += ftpr_converter_x(va_arg(args, int), 0);
	if (!ft_strncmp(s, "%X", 2))
		*r += ftpr_converter_x(va_arg(args, int), 1);
	if (!ft_strncmp(s, "%%", 2))
		*r += ftpr_converter_c('%');
	return (2);
}
