/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:14:06 by fmaurer           #+#    #+#             */
/*   Updated: 2024/06/15 08:36:04 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// determine length of split at hand.
static int	splitlen(const char *s, char c)
{
	int	k;

	k = 0;
	while (*s != c && *s)
	{
		s++;
		k++;
	}
	return (k);
}

// number of splits in string given.
// init splits = 1 because we return at least str unsplit.
// return 0 if str is empty or if only splits where found in s.
// do not count substrings of length 0!!
static int	numofsplits(const char *s, char c)
{
	int	splits;
	int	onlysplits;

	if (!*s)
		return (0);
	splits = 1;
	onlysplits = 1;
	while (*s)
	{
		if (*s != c)
			onlysplits = 0;
		if (*s == c && *(s + 1) != c && *(s + 1) && !onlysplits)
			splits++;
		s++;
	}
	return (splits * (!onlysplits));
}

// free all subarrays helper function in case subarray allocation goes wrong.
// tbh: seems a bit optional to me. how to fail malloc?
void	*free2stars(char **arr, int k)
{
	int	i;

	i = -1;
	while (++i < k)
		free(arr[i]);
	free(arr);
	return (NULL);
}

// inner loop split function. responsible for substring-array allocation. if
// anything goes wrong returns 0 for processing in ft_split func.
static int	copy_split(const char **s, char **substrs, char c, int i)
{
	char	*substr_ptr;

	substrs[i] = (char *) malloc(sizeof(char) * (splitlen(*s, c) + 1));
	if (!substrs[i])
		return (0);
	substr_ptr = substrs[i];
	while (**s != c && **s)
	{
		*substr_ptr = **s;
		(*s)++;
		substr_ptr++;
	}
	*substr_ptr = '\0';
	return (1);
}

// the only not so elegant is the ok flag. but apart from this... it is quite
// decent code.
char	**ft_split(char const *s, char c)
{
	char	**substrs;
	int		nsplits;
	int		i;
	int		ok;

	nsplits = numofsplits(s, c);
	substrs = (char **)malloc(sizeof(char *) * (nsplits + 1));
	if (!substrs)
		return (NULL);
	i = -1;
	ok = 1;
	while (++i < nsplits && ok)
	{
		while (*s == c && (*s != 0))
			s++;
		if (splitlen(s, c))
			ok = copy_split(&s, substrs, c, i);
	}
	if (!ok)
		return (free2stars(substrs, i - 1));
	substrs[nsplits] = NULL;
	return (substrs);
}
