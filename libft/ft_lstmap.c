/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 08:02:49 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/22 12:21:29 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// \o/ extra careful version \o/
//
// seperating call to `f` from the allocation of new list element. the problem:
// if we call:
// 		new_elem = ft_lstnew(f(lst->content));
// what happens of allocation of t_list elem in `ft_lstnew` fails? the call to
// `f` with arg lst->content happens *before* the allocation-try. so, if there
// is anything allocated by the f-function it will be lost in case the
// t_list-allocation in ft_lstnew fails.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*nhead;

	if (!lst || !f || !del)
		return (NULL);
	nhead = ft_lstnew(NULL);
	if (!nhead)
		return (NULL);
	nhead->content = f(lst->content);
	cur = nhead;
	lst = lst->next;
	while (lst)
	{
		cur->next = ft_lstnew(NULL);
		if (!cur->next)
		{
			ft_lstclear(&nhead, del);
			return (NULL);
		}
		cur = cur->next;
		cur->content = f(lst->content);
		lst = lst->next;
	}
	cur->next = NULL;
	return (nhead);
}
