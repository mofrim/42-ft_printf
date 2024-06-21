/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_convert_smpl_cdsi.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:18:16 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/21 12:31:27 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ftpr_printf.h"

int	ftpr_converter_i(int i)
{
	char	*num;
	int		r;

	num = ft_itoa(i);
	ft_putstr_fd(num, 1);
	r = ft_strlen(num);
	free(num);
	return (r);
}

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

int	ftpr_converter_c(int i)
{
	ft_putchar_fd(i, 1);
	return (1);
}

int	ftpr_converter_s(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
