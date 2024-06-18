/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:29:27 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/18 08:57:35 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 1stry libft-unit-test complained about not segfaulting with NULL-param. so i
// removed the check for it
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*byte_s;

	byte_s = (char *) s;
	i = 0;
	while (i < n)
	{
		byte_s[i] = c;
		i++;
	}
	return (s);
}
