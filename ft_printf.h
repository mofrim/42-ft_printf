/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:45:15 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/18 17:47:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// for the variadicness..
# include <stdarg.h>

int		ft_printf(const char *f, ...);
char	**ftp_split_fmt(const char *fmt, const char **conversions);
int		ftp_numofconvs(const char *s, const char **c);
int		ftp_simplescan(va_list args, char *fmt_str);

#endif // !FT_PRINTF_H
