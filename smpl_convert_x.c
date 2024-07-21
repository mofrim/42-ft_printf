/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_convert_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:03:27 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/12 11:21:45 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "ft_printf_bonus.h"
#else
# include "ft_printf.h"
#endif

static int	ftpr_hex_digits_int(unsigned int n)
{
	int	d;

	if (!n)
		return (1);
	d = 0;
	while (n)
	{
		n /= 16;
		d++;
	}
	return (d);
}

static char	*ftpr_hextoa_int(unsigned int n, int upper)
{
	char	*a;
	int		i;

	a = (char *)malloc(ftpr_hex_digits_int(n) * sizeof (char) + 1);
	if (!a)
		return (NULL);
	a[ftpr_hex_digits_int(n)] = '\0';
	i = ftpr_hex_digits_int(n);
	while (--i >= 0)
	{
		if (n % 16 < 10)
			a[i] = '0' + n % 16;
		else if (upper)
			a[i] = 'A' + (n % 16 - 10);
		else
			a[i] = 'a' + (n % 16 - 10);
		n /= 16;
	}
	return (a);
}

int	ftpr_converter_x(unsigned int i)
{
	char	*num;
	int		r;

	num = ftpr_hextoa_int(i, 0);
	ft_putstr(num);
	r = ft_strlen(num);
	free(num);
	return (r);
}

int	ftpr_converter_xupper(unsigned int i)
{
	char	*num;
	int		r;

	num = ftpr_hextoa_int(i, 1);
	ft_putstr(num);
	r = ft_strlen(num);
	free(num);
	return (r);
}
