/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_flagging_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:17:08 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/15 00:37:15 by fmaurer          ###   ########.fr       */
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
	flags->dot = 0;
	flags->prec = 0;
	flags->zero = 0;
	flags->space = 0;
	return (flags);
}

void	ftpr_print_flags(t_flags *fl)
{
	ft_printf("\n\n::: flagcheck :::\n");
	ft_printf("fl->plus = %d\n", fl->plus);
	ft_printf("fl->minus = %d\n", fl->minus);
	ft_printf("fl->hash = %d\n", fl->hash);
	ft_printf("fl->width = %d\n", fl->width);
	ft_printf("fl->dot = %d\n", fl->dot);
	ft_printf("fl->prec = %d\n", fl->prec);
	ft_printf("fl->zero = %d\n", fl->zero);
	ft_printf("fl->space = %d\n", fl->space);
	ft_printf("::: flagcheck end :::\n");
}
