/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:52:03 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/15 16:29:09 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "ft_printf_bonus.h"
#else 
# include "ft_printf.h"
#endif /* ifndef BONUS */

// take this if we are not doing the bonus part.
#ifndef BONUS

// check if substr at `s` is a simple conv or flagged conv
// Return Values:
// 		0	no conv
// 		1	only simple conv needed
int	ftpr_is_conversion(const char *s)
{
	if (ftpr_smpl_is_conv(s))
		return (1);
	return (0);
}

#endif /* ifndef BONUS */

int	ftpr_smpl_is_conv(const char *s)
{
	if (!ft_strncmp(s, "%c", 2) || !ft_strncmp(s, "%s", 2) || \
!ft_strncmp(s, "%p", 2) || !ft_strncmp(s, "%d", 2) || \
!ft_strncmp(s, "%i", 2) || !ft_strncmp(s, "%u", 2) || \
!ft_strncmp(s, "%x", 2) || !ft_strncmp(s, "%X", 2) || \
!ft_strncmp(s, "%%", 2))
		return (1);
	return (0);
}

// aaaah, this is a little bit dirty. i just let ftpr_smpl_convert return 2
// because it convenient for shortening code in ftpr_parse_args.
//
// TODO: actually there could be some real error handling be happening
// here. maybe...
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
		*r += ftpr_converter_x(va_arg(args, int));
	if (!ft_strncmp(s, "%X", 2))
		*r += ftpr_converter_xupper(va_arg(args, int));
	if (!ft_strncmp(s, "%%", 2))
		*r += ftpr_converter_c('%');
	return (2);
}
