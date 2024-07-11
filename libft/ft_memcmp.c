/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:09:07 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/14 16:27:45 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// DESCRIPTION
//   The memcmp() function compares the first n bytes (each interpreted as
//   unsigned char) of the memory areas s1 and s2.
//
// RETURN VALUE
//   The  memcmp()  function  returns an integer less than, equal to, or
//   greater than zero if the first n bytes of s1 is found, respectively,
//   to be less than, to match, or be greater than the first n bytes of s2.
//
//   For a nonzero return value, the sign is determined by the sign of the
//   difference between the first pair of bytes  (interpreted  as  unsigned
//   char) that differ in s1 and s2.
//
//   If n is zero, the return value is zero.
//
// NOTE: the same like memchr: only n limits comparison not NUL !!!
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	if (!n)
		return (0);
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
