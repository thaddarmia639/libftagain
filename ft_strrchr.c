/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsi <thsi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:02:50 by thsi              #+#    #+#             */
/*   Updated: 2026/09/22 16:18:36 by thsi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last);
}

// int	main(void)
// {
// 	const char	*str = "Hello, World!";
// 	int			c;
// 	char		*result;

// 	c = 'o';
// 	result = ft_strrchr(str, c);
// 	if (result != NULL)
// 		write(1, result, 1);
// 	return (0);
// }
