/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:48:15 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/14 15:06:53 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  strdup()  function  returns  a  pointer to a new string which is a
// duplicate of the string s.  Memory for the new string is obtained with mal‐
// loc(3), and can be freed with free(3).
//
// On success, the strdup() function returns a pointer to the duplicated string.
// It returns NULL if insufficient memory was available, with errno set to
// indicate the error.
//
// ERRORS
//    ENOMEM Insufficient memory available to allocate duplicate string.
char	*ft_strdup(const char *s)
{
	char	*c;
	int		i;

	c = (char *)malloc(ft_strlen(s) * sizeof (char) + 1);
	if (!c || !s)
		return (NULL);
	i = -1;
	while (s[++i])
		c[i] = s[i];
	c[i] = '\0';
	return (c);
}
