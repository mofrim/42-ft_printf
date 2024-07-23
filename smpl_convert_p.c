/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smpl_convert_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:17:25 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/23 08:41:09 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS
# include "ft_printf_bonus.h"
#else
# include "ft_printf.h"
#endif

static char	*hextoa_prefix(unsigned long n);

// we have to deal with unsigned long values and put them to hex
int	ftpr_converter_p(unsigned long l)
{
	char	*num;
	int		r;

	num = hextoa_prefix(l);
	if (!num)
		return (0);
	ft_putstr(num);
	r = ft_strlen(num);
	free(num);
	return (r);
}

static char	*hextoa_prefix(unsigned long n)
{
	char	*a;
	int		i;

	if (!n)
		return (ft_strdup("(nil)"));
	a = (char *)ft_calloc(ftpr_hex_digits(n) + 3, sizeof(char));
	if (!a)
		return (NULL);
	if (!ft_memcpy(a, "0x", 2))
		return (NULL);
	i = ftpr_hex_digits(n) + 2;
	while (--i >= 2)
	{
		if (n % 16 < 10)
			a[i] = '0' + n % 16;
		else
			a[i] = 'a' + (n % 16 - 10);
		n /= 16;
	}
	return (a);
}

int	ftpr_hex_digits(unsigned long n)
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
