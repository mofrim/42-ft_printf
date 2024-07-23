/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:43:54 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/18 09:18:45 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 1str try error: not returning dest when src == NULL
// aaaand: removed NULL check for *ALL* params because of francinette
// ***EXCEPT*** both params == NULL
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ds;
	char	*sr;

	if (!dest && !src)
		return (NULL);
	ds = (char *)dest;
	sr = (char *)src;
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dest);
}
