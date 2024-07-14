/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_compl_convert_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:09:58 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/15 00:02:17 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// for now: return -1 when anything goes wrong from here on down.
// return length of scanned conversion sequence including '%' and conv_char
//
// return conv_seq_len + 2 because of '%' and conv_char
int	ftpr_compl_convert(va_list args, const char *fmt, int *output)
{
	t_flags	*flags;
	int		conv_seq_len;

	flags = init_flags();
	conv_seq_len = 0;
	if (!flags)
		return (-1);
	while (!is_conv_char(*(++fmt)))
	{
		if (*fmt == '+')
			flags->plus = 1;
		if (*fmt == '-')
		{
			flags->minus = 1;
			if (flags->zero)
				flags->zero = 0;
		}
		if (*fmt == '.')
		{
			flags->dot = 1;
			flags->zero = 0;
			if (ft_isdigit(*(fmt + 1)))
			{
				flags->prec = ftpr_compl_atoi((fmt + 1));
				conv_seq_len += ft_strlen(ft_itoa(flags->prec)) - 1;
				fmt += ft_strlen(ft_itoa(flags->prec)) - 1;

			}
		}
		if (ft_isdigit(*fmt) && *fmt != '0' && !flags->dot)
		{
			flags->width = ftpr_compl_atoi(fmt);
			conv_seq_len += ft_strlen(ft_itoa(flags->width)) - 1;
			fmt += ft_strlen(ft_itoa(flags->width)) - 1;
		}
		if (ft_isdigit(*fmt) && *fmt != '0' && flags->dot)
		{
			flags->prec = ftpr_compl_atoi(fmt);
			conv_seq_len += ft_strlen(ft_itoa(flags->prec)) - 1;
			fmt += ft_strlen(ft_itoa(flags->prec)) - 1;
			break;
		}
		if (*fmt == '0' && !flags->width && !flags->dot && !flags->minus)
				flags->zero = 1;

		conv_seq_len++;
	}
	ftpr_compl_do_conv(args, *fmt, flags, output);
	return (conv_seq_len + 2);
}

static void	gather_flags(t_flags **flags, const char **fmt, int *conv_seq_len)
{


}
