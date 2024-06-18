/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 07:44:49 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/13 11:20:59 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == ' ' || c == '\v');
}

// well.. too. much. work. put into this!
// the logic is actually pretty simple:
// a single minus or plus is counted. everything else afterwards which is not a
// digit will be considered garbage and lead to return value 0.
// event INT_MIN is handled easily because somehow -(214748364 * 10 + 8) =
// INT_MIN automagically ?!
int	ft_atoi(const char *s)
{
	int	num;
	int	sgn;

	num = 0;
	sgn = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		sgn = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
		num = num * 10 + *s++ - '0';
	return (num * sgn);
}

// my brainfart version....
//
// static int	imin(int n, const char *s, int sgn)
// {
// 	if (sgn == 1)
// 		return (0);
// 	if ((n == -(INT_MIN / 10)) && (*s - 0 == -(INT_MIN % 10)) && !*(s++))
// 		return (1);
// 	return (0);
// }
//
// well... a bit hacky. escepcially the '-+' case is evil == 666. idk. maybe
// there is a deeper simpler logic, but glibc source is way to deep.
// int	ft_atoi(const char *s)
// {
// 	int	sgn;
// 	int	num;
// 	int	at;
// 	int	plus;
//
// 	sgn = 1;
// 	num = 0;
// 	plus = 0;
// 	while (ft_isspace(*s) && *s)
// 		s++;
// 	while (((*s == '+') || (*s == '-')) && !plus && *s)
// 	{
// 		sgn *= (*s == '-') * (-1) + (*s != '-');
// 		if (*s == '-' && *(s + 1) == '+')
// 			plus = 666;
// 		plus += (*s == '+');
// 		s++;
// 	}
// 	at = (ft_isdigit(*s) != 0) * (plus <= 1);
// 	while (ft_isdigit(*s) && *s && !imin(num, s, sgn) && at)
// 	{
// 		num = num * 10 + (*s - '0');
// 		s++;
// 	}
// 	return (imin(num, s, sgn) * INT_MIN + !imin(num, s, sgn) * at * num * sgn);
// }
