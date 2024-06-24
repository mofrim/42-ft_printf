/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_isconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:52:11 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/24 08:07:43 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// check if substr at `s` is a simple conv or flagged conv
// Return Values:
// 		-1	no conv
// 		0-...	simple conv index of conv in global
int	ftpr_is_conversion(const char *s)
{
	int	i;

	i = ftpr_is_smpl_conv(s);
	if (i >= 0)
		return (i);
	return (-1);
}
