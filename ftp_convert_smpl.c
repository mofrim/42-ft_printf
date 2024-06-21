/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_convert_smpl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:14:05 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/21 09:36:24 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp_printf.h"

static const char	*g_convs_smpl[] = { "%c", "%s", "%p", "%d", "%i", "%u", 
	"%x", "%X", "%%", NULL };

int	ftp_is_smpl_conv(const char *s)
{
	int	i;

	i = 0;
	while (g_convs_smpl[i])
	{
		if (!ft_strncmp(s, g_convs_smpl[i], ft_strlen(g_convs_smpl[i])))
			return (i);
		i++;
	}
	return (-1);
}

void	ftp_convert_smpl(va_list args, int conv_index, int *r)
{
	if (!ft_strncmp(g_convs_smpl[conv_index], "%c", 2))
		*r += ftp_converter_c(va_arg(args, int));
	if (!ft_strncmp(g_convs_smpl[conv_index], "%s", 2))
		*r += ftp_converter_s(va_arg(args, char *));
	if (!ft_strncmp(g_convs_smpl[conv_index], "%d", 2))
		*r += ftp_converter_d(va_arg(args, int));
}
