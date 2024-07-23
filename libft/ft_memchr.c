/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 21:22:12 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/14 16:22:28 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION The memchr() function scans the initial n bytes of the memory
// area pointed to by s for the first instance of c.  Both c and the bytes of
// the memory
//   area pointed to by s are interpreted as unsigned char.
//
//   The  memrchr() function is like the memchr() function, except that it
//   searches backward from the end of the n bytes pointed to by s instead
//   of for‐ ward from the beginning.
//
// RETURN VALUE
//   The memchr() and memrchr() functions return a pointer to the matching
//   byte or NULL if the character does not occur in the given memory area.
//
// NOTE: as we do not compare strings or anything NUL bytes are also allowed!
// Therefore only the memory size is limiting progress!

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
	}
	return (NULL);
}
