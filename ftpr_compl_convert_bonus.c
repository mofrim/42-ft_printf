/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_convert_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:09:58 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/15 01:11:15 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	get_prec_width(t_flags **fl, const char **fmt, int *conv_seq_len);

static void	get_pmshash(t_flags **fl, const char **fmt);

// for now: return -1 when anything goes wrong from here on down.
// return length of scanned conversion sequence including '%' and conv_char
//
// at function call fmt is pointing to '%'. if we init conv_seq_len = 1, then at
// the end we can add it to fmt and this will make point fmt to the first char
// after the convseq.
//
// NOTE: a bit ugly with this outsourcing of get_prec_width. still i want to
// note, that due to my intense testing of format string beforehand the case,
// where we get to extracting prec to flags->prec it is sure that there can only
// be the conv_char afterwards. this is already enforced through
// ftpr_compl_conv.
//
int	ftpr_compl_convert(va_list args, const char *fmt, int *output)
{
	t_flags	*flags;
	int		conv_seq_len;

	flags = init_flags();
	conv_seq_len = 1;
	if (!flags)
		return (-1);
	while (!is_conv_char(*(++fmt)))
	{
		get_pmshash(&flags, &fmt);
		get_prec_width(&flags, &fmt, &conv_seq_len);
		if (*fmt == '0' && !flags->width && !flags->dot && !flags->minus)
			flags->zero = 1;
		conv_seq_len++;
	}
	ftpr_compl_do_conv(args, *fmt, flags, output);
	ftpr_print_flags(flags);
	ft_printf("conv_seq_len = %d\n", conv_seq_len);
	free(flags);
	return (conv_seq_len);
}

static void	get_pmshash(t_flags **fl, const char **fmt)
{
	if (**fmt == '+')
	{
		(*fl)->plus = 1;
		(*fl)->space = 0;
	}
	if (**fmt == ' ' && !(*fl)->plus)
		(*fl)->space = 1;
	if (**fmt == '-')
	{
		(*fl)->minus = 1;
		(*fl)->zero = 0;
	}
	if (**fmt == '#')
		(*fl)->hash = 1;
}

static void	get_prec_width(t_flags **fl, const char **fmt, int *conv_seq_len)
{
	if (**fmt == '.')
	{
		(*fl)->dot = 1;
		(*fl)->zero = 0;
		if (ft_isdigit(*(*fmt + 1)))
		{
			(*fl)->prec = ftpr_compl_atoi((*fmt + 1));
			*conv_seq_len += ft_strlen(ft_itoa((*fl)->prec));
			fmt += ft_strlen(ft_itoa((*fl)->prec));
		}
	}
	if (ft_isdigit(**fmt) && **fmt != '0' && !(*fl)->dot)
	{
		(*fl)->width = ftpr_compl_atoi(*fmt);
		*conv_seq_len += ft_strlen(ft_itoa((*fl)->width)) - 1;
		(*fmt) += ft_strlen(ft_itoa((*fl)->width)) - 1;
	}
}
