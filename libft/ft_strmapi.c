/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:04:32 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/14 11:05:10 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//
// Parameters
// 		s: The string on which to iterate.
// 		f: The function to apply to each character.
// Return value
// 		The string created from the successive applications of ’f’.
// 		Returns NULL if the allocation fails.
// External functs.
// 		malloc
// Description
// 		Applies the function f to each character of the
// 		string s, passing its index as the first argument
// 		and the character itself as the second.
// 		A new string is created (using malloc(3)) to collect the
// 		results from the successive applications of f.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*nst;
	int		k;

	if (!s || !f)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	nst = (char *)malloc((ft_strlen(s) + 1) * sizeof (char));
	if (!nst)
		return (NULL);
	k = -1;
	while (s[++k])
		nst[k] = (*f)(k, s[k]);
	nst[k] = '\0';
	return (nst);
}
