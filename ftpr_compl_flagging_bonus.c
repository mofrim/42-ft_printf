/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_flagging_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:17:08 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/11 20:22:26 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// WARN: do not forget to free me!!!
t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *) malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->plus = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->width = 0;
	flags->prec = 0;
	flags->zero = 0;
	flags->space = 0;
	return (flags);
}
