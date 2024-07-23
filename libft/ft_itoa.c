/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:49:37 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/14 00:44:14 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dec(int n)
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

// Parameters
// 		n: the integer to convert.
// Return value
// 		The string representing the integer.
// 		NULL if the allocation fails.
// External functs.
// 		malloc
// Description
// 		Allocates (with malloc(3)) and returns a string
// 		representing the integer received as an argument.
// 		Negative numbers must be handled.
char	*ft_itoa(int n)
{
	char	*a;
	int		neg;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0);
	n *= (-1) * neg + (n >= 0);
	a = (char *)malloc(dec(n) * sizeof (char) + neg + 1);
	if (!a)
		return (NULL);
	if (neg)
		a[0] = '-';
	a[dec(n) + neg] = '\0';
	i = dec(n);
	while (--i >= 0)
	{
		a[neg + i] = '0' + n % 10;
		n /= 10;
	}
	return (a);
}
