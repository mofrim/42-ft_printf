/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_convert_smpl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:52:03 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/21 12:31:43 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpr_printf.h"

static const char	*g_convs_smpl[] = { "%c", "%s", "%p", "%d", "%i", "%u", 
	"%x", "%X", "%%", NULL };

int	ftpr_is_smpl_conv(const char *s)
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

void	ftpr_convert_smpl(va_list args, int conv_index, int *r)
{
	if (!ft_strncmp(g_convs_smpl[conv_index], "%c", 2))
		*r += ftpr_converter_c(va_arg(args, int));
	if (!ft_strncmp(g_convs_smpl[conv_index], "%s", 2))
		*r += ftpr_converter_s(va_arg(args, char *));
	if (!ft_strncmp(g_convs_smpl[conv_index], "%d", 2))
		*r += ftpr_converter_d(va_arg(args, int));
	if (!ft_strncmp(g_convs_smpl[conv_index], "%i", 2))
		*r += ftpr_converter_d(va_arg(args, int));
}
