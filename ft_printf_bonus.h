/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:26:13 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/12 00:03:23 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "ft_printf.h"

typedef struct s_flags
{
	int	plus;
	int	minus;
	int	hash;
	int	width;
	int	prec;
	int	zero;
	int	space;
}	t_flags;

int		ftpr_is_conversion(const char *s);
int		ftpr_is_compl_conv(const char *s);
int		ftpr_convert_compl(va_list args, const char *fmt, int *r);
t_flags	*init_flags(void);

int	is_flag_char(char c);
int	is_conv_char(char c);
int	is_valid_flagconv_char(char c);

#endif
