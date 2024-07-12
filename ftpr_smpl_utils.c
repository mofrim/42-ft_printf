/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_smpl_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:39:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/12 11:21:42 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "ft_printf_bonus.h"
#else
# include "ft_printf.h"
#endif

// some utitlity functions for ftpr

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

void	ft_putstr(char *s)
{
	ft_putstr_fd(s, 1);
}
