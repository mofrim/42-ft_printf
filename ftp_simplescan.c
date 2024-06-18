/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_simplescan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:23:09 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/18 22:33:58 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

// TODO: define elsewhere
const char *g_convs[] = { "%c", "%d", NULL };

int	is_conv(const char *s, const char **convs)
{
	int	i;

	i = 0;
	while (convs[i])
	{
		if (!ft_strncmp(s, convs[i], ft_strlen(convs[i])))
			return (i);
		i++;
	}
	return (-1);
}

int	ftp_handler_c(int i)
{
	ft_putchar_fd(i, 1);
	return (1);
}

void	handle_conv(va_list args, const char *conv, int *r)
{
	if (!ft_strncmp(conv, "%c", 3))
		r += ftp_handler_c(va_arg(args, int));
}

int	ftp_simplescan(va_list args, char *fmt_str)
{
	int	c;
	int	r;

	r = 0;
	while (*fmt_str)
	{
		c = is_conv(fmt_str, g_convs);
		if (c >= 0)
		{
			handle_conv(args, g_convs[c], &r);
			fmt_str += ft_strlen(g_convs[c]);
		}
		ft_putchar_fd(*fmt_str, 1);
		r++;
		fmt_str++;
	}
	return (r);
}
