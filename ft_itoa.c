/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsi <thsi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 20:39:25 by thsi              #+#    #+#             */
/*   Updated: 2026/10/19 20:33:49 by thsi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	count;

	count = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	int		is_negative;
	char	*result;

	num = (long)n;
	is_negative = (num < 0);
	len = count_digits(num) + is_negative;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	if (num == 0)
		result[len - 1] = '0';
	while (num > 0)
	{
		result[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}

// #include <stdio.h>

// int main(void)
// {
//     char *s;

//     s = ft_itoa(12345);
//     printf("[%s]\n", s);
//     free(s);

//     s = ft_itoa(-987);
//     printf("[%s]\n", s);
//     free(s);

//     s = ft_itoa(0);
//     printf("[%s]\n", s);
//     free(s);

//     s = ft_itoa(-2147483648);
//     printf("[%s]\n", s);
//     free(s);

//     return (0);
// }
