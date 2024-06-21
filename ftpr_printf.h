/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:45:15 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/21 11:47:49 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// for the variadicness..
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags {
	int conv;
	int hashtag;
	int plus;
	int minus;
	int zero;
	int prec;
	int space;
	int width;
	int star;
}	t_flags;

//utils
void	ft_putchar(char c);

int		ft_printf(const char *f, ...);
char	**ftp_split_fmt(const char *fmt, const char **conversions);
int		ftp_numofconvs(const char *s, const char **c);
int		ftp_simplescan(va_list args, char *fmt_str);

int		ftp_is_conversion(const char *s);
int		ftp_is_smpl_conv(const char *s);
void	ftp_convert_smpl(va_list args, int conv_index, int *r);
int		ftp_converter_c(int i);
int		ftp_converter_s(char *str);
int		ftp_converter_d(int i);

int	ftp_is_flagged_conv(const char *s);
#endif // !FT_PRINTF_H
