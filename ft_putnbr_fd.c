/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsi <thsi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:19:00 by thsi              #+#    #+#             */
/*   Updated: 2026/09/22 16:25:35 by thsi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	put_positive(long n, int fd)
{
	char	c;

	if (n >= 10)
		put_positive(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	put_positive(num, fd);
}

// int main(void)
// {
//     ft_putnbr_fd(12345, 1);
//     ft_putnbr_fd(0, 1);
//     ft_putnbr_fd(-42, 1);
//     ft_putnbr_fd(-2147483648, 1);
//     return (0);
// }
