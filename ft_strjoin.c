/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsi <thsi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 17:28:48 by thsi              #+#    #+#             */
/*   Updated: 2026/09/21 17:35:03 by thsi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*join(char const *str, char *dest, size_t start)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		dest[start + i] = str[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(len1 + len2 + 1);
	if (!new)
		return (NULL);
	join(s1, new, 0);
	join(s2, new, len1);
	new[len1 + len2] = '\0';
	return (new);
}
