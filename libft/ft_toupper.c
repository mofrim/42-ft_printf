/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:15:06 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/08 01:52:09 by fmaurer          ###   ########.fr       */
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
int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		return (c - 32);
	if (c == -1)
		return (c);
	if (-128 <= c && c < -1)
		return ((unsigned char) c);
	if (c < -128)
		return (c);
	return (c);
}
