/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_converter_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:51:28 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/21 11:51:30 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpr_printf.h"

int	ftpr_converter_d(int i)
{
	char	*num;
	int		r;

	num = ft_itoa(i);
	ft_putstr_fd(num, 1);
	r = ft_strlen(num);
	free(num);
	return (r);
}
