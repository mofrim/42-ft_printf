/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:05:35 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/13 16:28:21 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Parameters
// 		s1: The prefix string.
// 		s2: The suffix string.
// Return value
// 		The new string.
// 		NULL if the allocation fails.
// External functs.
// 		malloc
// Description
// 		Allocates (with malloc(3)) and returns a new
// 		string, which is the result of the concatenation
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joi;
	char	*bak;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	joi = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof (char) + 1);
	bak = joi;
	if (!joi)
		return (NULL);
	while (*s1)
		*joi++ = *s1++;
	while (*s2)
		*joi++ = *s2++;
	*joi = '\0';
	return (bak);
}
