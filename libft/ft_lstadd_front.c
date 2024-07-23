/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 01:03:02 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/16 19:40:36 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// the `*head = newhead` makes the main program pointer `t_list *head` point to
// `newhead`. Now the main program pointer `head` points to `newhead`. By doing
// this, we ensure that every reference to `head` now accesses `newhead`. By
// `newhead->next = *head` the old head becomes the 2nd element of the list.
//
// this example code:
//
// 		t_list *head = ft_lstnew("head");
// 		t_list *sec = ft_lstnew("second");
// 		t_list *newhead = ft_lstnew("newhead");
//
// 		head->next = sec;
// 		sec->next = NULL;
// 		sec->content = head->content;
// 		printf("head->content = %s\n", (char  *)head->content);
// 		printf("sec->content = %s\n", (char *)sec->content);
// 		printf("newhead->content = %s\n", (char *)newhead->content);
// 		ft_lstadd_front(&head, newhead);
// 		printf("head->content = %s\n", (char  *)head->content);
// 		printf("sec->content = %s\n", (char *)sec->content);
// 		printf("newhead->content = %s\n", (char *)newhead->content);
//
// outputs:
//
// 		head->content = head
// 		sec->content = head
// 		newhead->content = newhead
//
// 		head->content = newhead
// 		sec->content = head
// 		newhead->content = newhead
//
// conclusion: it works :)
void	ft_lstadd_front(t_list **head, t_list *newhead)
{
	if (!head || !newhead)
		return ;
	newhead->next = *head;
	*head = newhead;
}
