/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpr_utoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:49:37 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/22 10:36:30 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dec(unsigned int n)
{
	int	d;

	if (!n)
		return (1);
	d = 0;
	while (n)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char	*ftpr_utoa(unsigned int n)
{
	char	*a;
	int		i;

	a = (char *)malloc(dec(n) * sizeof (char) + 1);
	if (!a)
		return (NULL);
	a[dec(n)] = '\0';
	i = dec(n);
	while (--i >= 0)
	{
		a[i] = '0' + n % 10;
		n /= 10;
	}
	return (a);
}
