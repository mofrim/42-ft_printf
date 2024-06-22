/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:37:55 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/18 09:14:57 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if 
// 		src:  1|2|3|4
// 		dest:  |0|0|0|0
// the this algorithm ensures that the copying would happen like this: 1) 4 ->
// dest[3], 2) 3 -> dest[2] which equals src[3] overwriting this, which is not a
// problem because it already got copied.
//
// remove *ALL* NULL check because of franci ***EXCEPT*** the one where both
// params == NULL
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ds;
	char	*sr;

	if (!dest && !src)
		return (NULL);
	ds = (char *) dest;
	sr = (char *) src;
	if (src < dest)
		while (n--)
			ds[n] = sr[n];
	else
		while (n--)
			*(ds++) = *(sr++);
	return (dest);
}
