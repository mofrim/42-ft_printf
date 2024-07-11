/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:22:09 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/13 13:47:04 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
