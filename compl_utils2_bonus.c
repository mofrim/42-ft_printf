/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:39:17 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/19 22:21:09 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ftpr_unumstrlen(unsigned int d)
{
	char	*numstr;
	int		ret;

	numstr = ftpr_utoa(d);
	if (!numstr)
		return (0);
	ret = ft_strlen(numstr);
	free(numstr);
	return (ret);
}

void	ftpr_print_zerox(int doit, int c, unsigned int num)
{
	if (!doit || !num)
		return ;
	if (c == 'x')
		ft_putstr("0x");
	if (c == 'X')
		ft_putstr("0X");
}
