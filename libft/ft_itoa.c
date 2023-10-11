/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:01:21 by jkauker           #+#    #+#             */
/*   Updated: 2023/10/11 21:24:51 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_digits(long n)
{
	long	digits;

	digits = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

void	put_nb_in_str(long n, long digits, char *str)
{
	str[digits + 1] = 0;
	while (n > 0)
	{
		str[digits] = (n % 10) + '0';
		digits--;
		n /= 10;
	}
}

//onlz minus not working

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	long	_n;

	_n = n;
	digits = get_digits(_n);
	if (_n < 1)
	{
		digits += 1;
		str = malloc((digits + 1) * sizeof(char));
		if (!str)
			return (0);
		str[0] = '-';
		_n = -_n;
	}
	else
	{
		str = malloc((digits + 1) * sizeof(char));
		if (!str)
			return (0);
	}
	put_nb_in_str(n, digits, str);
	return (str);
}
