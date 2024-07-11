/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:39:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/11 10:23:50 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// some utitlity functions for ftpr

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

void	ft_putstr(char *s)
{
	ft_putstr_fd(s, 1);
}
