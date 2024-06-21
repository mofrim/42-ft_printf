/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_converter_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:27:08 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/21 09:36:20 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp_printf.h"

int	ftp_converter_d(int i)
{
	char	*num;
	int		r;

	num = ft_itoa(i);
	ft_putstr_fd(num, 1);
	r = ft_strlen(num);
	free(num);
	return (r);
}
