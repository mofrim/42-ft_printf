/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_convert_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:09:58 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/23 10:17:47 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	get_prec_width(t_flags **fl, const char **fmt, int *conv_seq_len);

static void	get_pmshash(t_flags **fl, const char **fmt);

static void	get_zero(t_flags **fl, const char **fmt);

/*
 * Gathers flags into t_flags struct and executes conversion with that.
 *
 * @return Length of scanned conversion sequence including '%' and conv_char
 *
 * At function call fmt is pointing to '%'. we have at least the '%' and a conv
 * char. if we init conv_seq_len = 2, then at the end we can add it to fmt and
 * this will make point fmt to the first char after the convseq.
 *
 * NOTE: I want to note, that due to my intense testing of format string
 * beforehand at the point we get to extracting prec to flags->prec it is
 * sure that there can only be the conv_char afterwards. this is already
 * enforced through ftpr_compl_conv.
 */
int	ftpr_gather_flags_and_conv(va_list args, const char *fmt, int *output)
{
	t_flags	*flags;
	int		conv_seq_len;

	flags = init_flags();
	if (!flags)
		return (-1);
	conv_seq_len = 2;
	while (ftpr_isflagconv(*(++fmt)) != 1)
	{
		get_pmshash(&flags, &fmt);
		get_prec_width(&flags, &fmt, &conv_seq_len);
		get_zero(&flags, &fmt);
		conv_seq_len++;
	}
	ftpr_compl_do_conv(args, *fmt, flags, output);
	free(flags);
	return (conv_seq_len);
}

/* Helper function. Gather "+ -#" flags. */
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

/* Helper func. Gather prec and width. */
static void	get_prec_width(t_flags **fl, const char **fmt, int *conv_seq_len)
{
	char	*tmp;

	if (**fmt == '.')
	{
		(*fl)->dot = 1;
		(*fl)->zero = 0;
		if (ft_isdigit(*(*fmt + 1)))
		{
			(*fl)->prec = ftpr_atoi_overflow((*fmt + 1));
			tmp = ft_itoa((*fl)->prec);
			*conv_seq_len += ft_strlen(tmp);
			(*fmt) += ft_strlen(tmp);
			free(tmp);
		}
	}
	if (ft_isdigit(**fmt) && **fmt != '0' && !(*fl)->dot)
	{
		(*fl)->width = ftpr_atoi_overflow(*fmt);
		tmp = ft_itoa((*fl)->width);
		*conv_seq_len += ft_strlen(tmp) - 1;
		(*fmt) += ft_strlen(tmp) - 1;
		free(tmp);
	}
}

/* Helper function. Gather zero flag. */
static void	get_zero(t_flags **fl, const char **fmt)
{
	if (**fmt == '0' && !(*fl)->width && !(*fl)->dot && !(*fl)->minus)
		(*fl)->zero = 1;
}
