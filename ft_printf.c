/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:43:28 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/18 15:49:54 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	ftprntf_parse_args(va_list args, char *str)
{
	printf("args = %p", &args);
	printf("args = %p", &args);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	char	*fmt_str;
	int		printed;

	if (!fmt || !*fmt)
		return (0);
	fmt_str = ft_strdup(fmt);
	if (!fmt_str || !*fmt_str)
		return (0);
	va_start(args, fmt);
	printed = ftprntf_parse_args(args, fmt_str);
	va_end(args);
	free(fmt_str);
	return (printed);
}
