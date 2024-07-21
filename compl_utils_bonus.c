/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:43:50 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/21 09:12:19 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

// TODO: REFAC: merge to one func with different rvals.
//

// cspdiuxX%
int	is_conv_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	is_flag_char(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '#' || c == '0')
		return (1);
	return (0);
}

int	is_valid_flagconv_char(char c)
{
	if (is_flag_char(c) || is_conv_char(c) || ft_isdigit(c) || c == '.')
		return (1);
	return (0);
}
//
// TODO: REFAC end

// well, i need an atoi which detects a possible overflow. input is a
// string of digits representing a non-negtive number
int	ftpr_compl_atoi(const char *s)
{
	long	num;

	num = 0;
	while (ft_isdigit(*s))
	{
		num = num * 10 + *s++ - '0';
		if (num > INT_MAX)
			return (-1);
	}
	return ((int)num);
}

// @brief Text.
int	ftpr_numstrlen(int d)
{
	char	*numstr;
	int		ret;

	numstr = ft_itoa(d);
	if (!numstr)
		return (0);
	ret = ft_strlen(numstr);
	free(numstr);
	return (ret);
}
