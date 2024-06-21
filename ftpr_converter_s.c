/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_converter_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:51:36 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/21 11:51:37 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpr_printf.h"

int	ftpr_converter_s(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
