/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_both_check_fmt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:26:06 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/13 14:51:34 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "ft_printf_bonus.h"
#else
# include "ft_printf.h"
#endif

/**
 * checks for incomplete conversions
 *
 * this is necessary in case of incomplete conversions present in fmt_string
 * nothing should be printed at all and -1 be be returned by ft_printf.
 */

#ifdef BONUS

int	ftpr_check_fmt(const char *fmt)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (ftpr_compl_is_conv(fmt) == -1)
				return (0);
		}
		fmt++;
	}
	return (1);
}

#else

// in mandatory / smpl case we do not know anything about any flags ;)
//
// so, the only possibility vor invalid conversions we can check here: do we
// have a fmt string like "%" or "*****%", which is, the fmtstring is somehow
// ending with a %.
int	ftpr_check_fmt(const char *fmt)
{
	if (!ft_strlen(fmt))
		return (1);
	fmt += ft_strlen(fmt) - 1;
	if (*fmt == '%')
		return (0);
	return (1);
}

#endif 
