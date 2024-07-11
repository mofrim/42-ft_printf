/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:58:57 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/17 18:32:30 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 2nd if: empty list given as NULL
// "always ensuring that newend->next == NULL"
// ...francinette does not like it. but it actually makes sense to me. still i
// will remove it. maybe it is better not to touch newend...
void	ft_lstadd_back(t_list **head, t_list *newend)
{
	t_list	*oldlast;

	if (!newend)
		return ;
	if (!*head)
	{
		*head = newend;
		return ;
	}
	oldlast = ft_lstlast(*head);
	oldlast->next = newend;
}
