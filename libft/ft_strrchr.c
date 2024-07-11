/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:10:43 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/14 15:53:42 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *) s;
	p = p + ft_strlen(s);
	while (p != s)
	{
		if ((unsigned char)*p == (unsigned char)c)
			return (p);
		p--;
	}
	if ((unsigned char)*p == (unsigned char)c)
		return (p);
	return (NULL);
}
