/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:41:20 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/16 19:52:00 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// prequisite: argument is first element of list
int	ft_lstsize(t_list *head)
{
	t_list	*cur;
	int		i;

	if (head == NULL)
		return (0);
	cur = head;
	i = 1;
	while (cur->next != NULL)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}
