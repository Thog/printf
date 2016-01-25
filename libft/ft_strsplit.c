/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:59:45 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/04 10:58:58 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(const char *str, char separator)
{
	size_t	i;
	size_t	index;
	int		l;

	i = 0;
	index = 0;
	l = 1;
	while (str[index])
	{
		if (str[index] == separator)
			l = 1;
		else if (l)
		{
			l = 0;
			i++;
		}
		index++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int			start;
	int			l;
	size_t		i;
	char const	*tmp;
	char		**result;

	l = 1;
	i = 0;
	tmp = s;
	start = 0;
	result = (char **)ft_memalloc(sizeof(char*) * (count_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	while (*tmp && count_words(s, c) != 1)
	{
		if (*tmp == c && !l && ((l = 1) + 1))
			result[i++] = ft_strsub(s, start, (tmp - s) - start);
		else if (*tmp != c && l && ((l = 0) + 1))
			start = tmp - s;
		tmp++;
	}
	if (count_words(s, c) == 1)
		result[i++] = ft_strdup(ft_strtrimch(s, c));
	result[i] = NULL;
	return (result);
}
