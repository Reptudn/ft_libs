/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:01:21 by jkauker           #+#    #+#             */
/*   Updated: 2023/10/09 17:02:14 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	int	digits;

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

void	put_nb_in_str(int n, int digits, char *str)
{
	str[digits] = 0;
	while (n > 0)
	{
		str[digits - 1] = (n % 10) + '0';
		digits--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	digits = get_digits(n);
	if (n == 0)
		return ("0");
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 1)
	{
		digits++;
		str = malloc((digits + 1) * sizeof(char));
		str[0] = '-';
		n = -n;
	}
	else
		str = malloc((digits + 1) * sizeof(char));
	if (!str)
		return (0);
	put_nb_in_str(n, digits, str);
	return (str);
}
