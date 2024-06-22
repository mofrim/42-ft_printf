/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:20:43 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/08 01:54:09 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the manual informs:
//
// The standards require that the argument c for these functions is either EOF
// or a value that is representable in the type un‐ signed char.  If the
// argument c is of type char, it must be cast to unsigned char
//
// ... still i want to make sure this works even if moulinette is not casting
// anything 
int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
		return (c + 32);
	if (c == -1)
		return (c);
	if (-128 <= c && c < -1)
		return ((unsigned char) c);
	if (c < -128)
		return (c);
	return (c);
}
