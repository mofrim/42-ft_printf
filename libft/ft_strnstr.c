/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:27:50 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/12 07:42:58 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// line 25: had to use comparison len >= llen in order not to cast to smaller
// type. before i had len - llen >= 0 which would never be negtive cause of
// size_t types.
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;

	llen = ft_strlen(little);
	if (!llen)
		return ((char *)big);
	while (*big && len)
	{
		if (!ft_strncmp(big, little, llen) && (len >= llen))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
