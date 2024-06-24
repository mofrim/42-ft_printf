/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:45:15 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/24 08:07:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// for the variadicness..
# include "libft/libft.h"
# include <stdarg.h>

//utils
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ftpr_utoa(unsigned int n);
int		ftpr_hex_digits(unsigned long n);
char	*ftpr_hextoa_prefix(unsigned long n);

int		ft_printf(const char *f, ...);
int		ftpr_parse_args(va_list args, char *fmt_str);

int		ftpr_is_conversion(const char *s);
int		ftpr_is_smpl_conv(const char *s);
void	ftpr_convert_smpl(va_list args, int conv_index, int *r);
int		ftpr_converter_c(int i);
int		ftpr_converter_s(char *str);
int		ftpr_converter_d(int i);
int		ftpr_converter_u(unsigned int i);
int		ftpr_converter_p(unsigned long l);
int		ftpr_converter_x(unsigned int i);
int		ftpr_converter_xupper(unsigned int i);
#endif
