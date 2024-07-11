/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_convert_compl_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:23:55 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/11 18:45:29 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// check if substr at `s` is a simple conv or flagged conv
// Return Values:
// 		0	no conv
// 		1	only simple conv needed
// 		-1	complex conversion
int	ftpr_is_conversion(const char *s)
{
	if (ftpr_is_smpl_conv(s))
		return (1);
	if (*s == '%' && ftpr_is_compl_conv(s))
		return (-1);
	return (0);
}

// TODO: how to determine valid complex conv?
int	ftpr_is_compl_conv(const char *s)
{
	(void) s;
	return (0);
}
