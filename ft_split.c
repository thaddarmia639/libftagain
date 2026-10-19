/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsi <thsi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 20:28:41 by thsi              #+#    #+#             */
/*   Updated: 2026/09/22 22:12:56 by thsi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	countwords(char const *s, char c)
{
	size_t	count;
	int		inword;

	count = 0;
	inword = 0;
	while (*s)
	{
		if (*s != c && !inword)
		{
			inword = 1;
			count++;
		}
		else if (*s == c)
			inword = 0;
		s++;
	}
	return (count);
}

static void	freeall(char **result, size_t i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
}

static char	**fillwords(char const *s, char c, char **result)
{
	size_t		i;
	char const	*start;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (s > start)
		{
			result[i] = ft_substr(start, 0, s - start);
			if (!result[i])
			{
				freeall(result, i);
				return (NULL);
			}
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = countwords(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	if (!fillwords(s, c, result))
		return (NULL);
	return (result);
}
