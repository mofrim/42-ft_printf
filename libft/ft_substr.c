/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:56:41 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/15 00:02:44 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Parameters
// 		s: The string from which to create the substring.
// 		start: The start index of the substring in the string ’s’.
// 		len: The maximum length of the substring.
// Return value
// 		The substring. NULL if the allocation fails.
// External functs. 
// 		malloc
// Description
// 		Allocates (with malloc(3)) and returns a substring
// 		from the string ’s’.
// 		The substring begins at index ’start’ and is of
// 		maximum size ’len’.
// NOTE: well... who would be so crazy allocating ULONG_MAX bytes of memory???
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	mlen;

	if (start < ft_strlen(s) && ft_strlen(s) - start <= len)
		return (ft_strdup(s + start));
	if (start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	mlen = (len == ULONG_MAX) * ULONG_MAX + (len + 1) * (len != ULONG_MAX);
	sub = (char *)ft_calloc(mlen, sizeof(char));
	if (!sub || !s)
		return (NULL);
	i = start;
	while (s[i] && (i - (size_t)start) < len)
	{
		sub[i - start] = s[i];
		i++;
	}
	sub[i - start] = '\0';
	return (sub);
}
