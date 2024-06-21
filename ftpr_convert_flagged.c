/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_convert_flagged.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:51:46 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/21 11:51:47 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpr_printf.h"

/* the valid structure of any conversion spec should be:
 *
 * 		%[$][flags][width][.precision]conversion
 *
 * flags: # .+-0
 *
 *
 *
 *
 *
 *
 *
 */

char	ftpr_is_valid_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' \
		|| c == 'x' || c == 'X')
		return (c);
	return (0);
}

char	ftpr_is_valid_flag(char c)
{
	if (c == '#' || c == ' ' || c == '.' || c == '+' || c == '-' || c == '0')
		return (c);
	return (0);

}

int	ftpr_collect_flags(const char *s, t_flags *flags)
{
}

// is there a combination of valid flags that is not valid?
// %+-+.50#x
int	ftpr_is_flagged_conv(const char *s)
{
	if (*s != '%')
		return (0);
}
