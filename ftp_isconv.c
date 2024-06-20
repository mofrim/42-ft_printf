/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_isconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:34:58 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/20 22:13:48 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>

static const char	*g_convs_smpl[] = { "%c", "%s", "%p", "%d", "%i", "%u", 
	"%x", "%X", "%%", NULL };

int	ftp_is_simple_conv(const char *s)
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

int	ftp_flag_cond(const char *s)
{
	(void)s;
	return (0);
}

int	ftp_is_flagged_conv(const char *s)
{
	if (*s == '%' && ftp_flag_cond(s))
		return (1);
	return (0);
}

// check if substr at `s` is a simple conv or flagged conv
// Return Values:
// 		-1	no conv
// 		0-...	simple conv index of conv in global
// 		-2	flagged conv
int	ftp_is_conversion(const char *s)
{
	int	i;

	i = ftp_is_simple_conv(s);
	if (0 <= i)
		return (i);
	if (ftp_is_flagged_conv(s))
		return (-2);
	return (-1);
}
