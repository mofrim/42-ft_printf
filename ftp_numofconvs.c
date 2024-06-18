/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_numofconvs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:03:26 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/18 17:05:17 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

// number of conversions in string given.
int	ftp_numofconvs(const char *s, const char **c)
{
	char		*p;
	const char	*sb;
	int			nc;
	int			i;

	nc = 0;
	i = 0;
	sb = s;
	while (c[i])
	{
		p = ft_strnstr(s, c[i], ft_strlen(s));
		if (p)
		{
			nc++;
			s = p + ft_strlen(c[i]);
		}
		if (!p)
		{
			i++;
			s = sb;
		}
	}
	return (nc);
}
