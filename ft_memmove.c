/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsi <thsi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:38:20 by thsi              #+#    #+#             */
/*   Updated: 2026/09/20 19:38:27 by thsi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dst == NULL || src == NULL)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d <= s)
		return (ft_memcpy(dst, src, n));
	i = n;
	while (i > 0)
	{
		i--;
		d[i] = s[i];
	}
	return (dst);
}
