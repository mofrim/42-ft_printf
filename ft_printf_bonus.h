/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:26:13 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/15 01:28:53 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	plus;
	int	minus;
	int	hash;
	int	width;
	int	dot;
	int	prec;
	int	zero;
	int	space;
	int	padding;
}	t_flags;

int		ftpr_compl_is_conv(const char *s);
int		ftpr_check_fmt(const char *fmt);
int		ftpr_compl_convert(va_list args, const char *fmt, int *r);
int		ftpr_compl_do_conv(va_list args, char conv, t_flags *flags, \
int *output);

int		ftpr_compl_converter_d(int d, t_flags *flags);

t_flags	*init_flags(void);
void	ftpr_print_flags(t_flags *fl);

int		is_flag_char(char c);
int		is_conv_char(char c);
int		is_valid_flagconv_char(char c);
int		ftpr_compl_atoi(const char *s);

// from smpl ft_printf.h
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ftpr_utoa(unsigned int n);
int		ftpr_hex_digits(unsigned long n);
char	*ftpr_hextoa_prefix(unsigned long n);

int		ft_printf(const char *f, ...);
int		ftpr_parse_args(va_list args, const char *fmt);

int		ftpr_is_conversion(const char *s);
int		ftpr_smpl_is_conv(const char *s);
int		ftpr_smpl_convert(va_list args, const char *s, int *r);
int		ftpr_converter_c(int i);
int		ftpr_converter_s(char *str);
int		ftpr_converter_d(int i);
int		ftpr_converter_u(unsigned int i);
int		ftpr_converter_p(unsigned long l);
int		ftpr_converter_x(unsigned int i);
int		ftpr_converter_xupper(unsigned int i);

#endif
