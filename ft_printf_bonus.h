/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:26:13 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/23 08:27:35 by fmaurer          ###   ########.fr       */
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
}	t_flags;

//
// TODO: sort all funcs in order of possible code execution
//

int		ft_printf(const char *f, ...);
int		ftpr_parse_args(va_list args, const char *fmt);
int		ftpr_check_fmt(const char *fmt);
int		ftpr_compl_isconv(const char *s);
int		ftpr_compl_convert(va_list args, const char *fmt, int *r);
int		ftpr_compl_do_conv(va_list args, char conv, t_flags *flags, \
int *output);

// the workers
int		ftpr_compl_converter_d(int d, t_flags *flags);
int		ftpr_compl_converter_u(unsigned int d, t_flags *flags);
int		ftpr_compl_converter_c(int c, t_flags *flags);
int		ftpr_compl_converter_s(char *s, t_flags *fl);
int		ftpr_compl_converter_p(unsigned long p, t_flags *fl);
int		ftpr_compl_converter_x(unsigned int i, t_flags *fl, int c);

// flag related
t_flags	*init_flags(void);
void	ftpr_print_flags(t_flags *fl);

// bonus utils
int		ftpr_isflagconv(char c);
int		ftpr_atoi_overflow(const char *s);
int		ftpr_intstrlen(int d);
int		ftpr_uintstrlen(unsigned int d);
void	ftpr_print_zerox(int doit, int c, unsigned int num);

// from smpl ft_printf.h
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ftpr_utoa(unsigned int n);
int		ftpr_hex_digits(unsigned long n);
char	*ftpr_hextoa_prefix(unsigned long n);

int		ftpr_is_conversion(const char *s);
int		ftpr_smpl_isconv(const char *s);
int		ftpr_smpl_convert(va_list args, const char *s, int *r);
int		ftpr_converter_c(int i);
int		ftpr_converter_s(char *str);
int		ftpr_converter_d(int i);
int		ftpr_converter_u(unsigned int i);
int		ftpr_converter_p(unsigned long l);
int		ftpr_converter_x(unsigned int i);
int		ftpr_converter_xupper(unsigned int i);

#endif
