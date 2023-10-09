/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:18:27 by jonask            #+#    #+#             */
/*   Updated: 2023/10/09 15:22:37 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_special(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else if (n == 2147483647)
	{
		write(fd, "2147483647", 1);
		return (1);
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 1);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (is_special(n, fd) == 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		c = n % 10;
		write(fd, &c, 1);
		n /= 10;
	}
}
