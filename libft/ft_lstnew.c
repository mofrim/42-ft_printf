/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:47:06 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/17 08:31:27 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nn;

	nn = (t_list *)malloc(sizeof(t_list));
	if (!nn)
		return (NULL);
	nn->content = content;
	nn->next = NULL;
	return (nn);
}
