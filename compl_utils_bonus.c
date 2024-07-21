/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:43:50 by fmaurer           #+#    #+#             */
/*   Updated: 2024/07/21 15:15:22 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft/libft.h"

/**
 * Combined flag or conv char testing func.
 *
 * If you want to test for flagconvness f.ex. use `if(is_valid_flagconv(c))`
 *
 * @param c The char to be tested for flagconvness.
 * @return Returns
 * 			1	if c is a conv char
 * 			2	if c is a flag char
 * 			3	if c is a digit or dot
 */

int	ftpr_isflagconv(char c)
{
	int	rval;

	rval = 0;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
c == 'u' || c == 'x' || c == 'X' || c == '%')
		rval = 1;
	if (c == ' ' || c == '+' || c == '-' || c == '#' || c == '0')
		rval = 2;
	if ((ft_isdigit(c) || c == '.') && c != '0')
		rval = 3;
	return (rval);
}

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
