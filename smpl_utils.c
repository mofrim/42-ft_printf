/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:39:47 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/23 12:40:44 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "ft_printf_bonus.h"
#else
# include "ft_printf.h"
#endif

/* Output one char to stdout. */
void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

/* Output string to stdout. */
void	ft_putstr(char *s)
{
	ft_putstr_fd(s, 1);
}
