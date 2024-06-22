/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:38:39 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/18 08:29:53 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// maybe usage gets clearer if you look at a real-life example:
//
// char *dir,	*file, pname[MAXPATHLEN];
// size_t n;
// ...
// if	(strlcat(pname,	file, sizeof(pname)) >=	sizeof(pname))
// 	goto toolong;
//
// 1st try error: in
// 		if (dsiz <= ft_strlen(dst))
// i had a '<' so the return value would be wrong

size_t	ft_strlcat(char *dst, const char *src, size_t dsiz)
{
	size_t	k;
	size_t	dlen;

	if (dsiz <= ft_strlen(dst))
		return (ft_strlen(src) + dsiz);
	dlen = ft_strlen(dst);
	k = 0;
	while ((k < dsiz - dlen - 1) && src[k])
	{
		dst[dlen + k] = src[k];
		k++;
	}
	if (dlen < dsiz)
		dst[k + dlen] = '\0';
	return (dlen + ft_strlen(src));
}
