/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:54:55 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/16 19:58:40 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// arg is again first element of list
t_list	*ft_lstlast(t_list *head)
{
	t_list	*cur;

	if (head == NULL)
		return (NULL);
	cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	return (cur);
}
