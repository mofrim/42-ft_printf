/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:05:56 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/14 15:20:18 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Parameters
// 		s: The string on which to iterate.
// 		f: The function to apply to each character.
// Return value
// 		None
// External functs.
// 		None
// Description
// 		Applies the function ’f’ on each character of
// 		the string passed as argument, passing its index
// 		as first argument.
// 		Each character is passed by
// 		address to ’f’ to be modified if necessary.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	long	k;

	if (!s || !f)
		return ;
	if (!f)
		return ;
	k = -1;
	while (s[++k])
		(*f)((unsigned int)k, &s[k]);
}
