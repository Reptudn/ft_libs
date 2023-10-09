/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:01:21 by jkauker           #+#    #+#             */
/*   Updated: 2023/10/09 16:45:42 by jkauker          ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	digits = get_digits(n);
	if (n < 1)
	{
		digits++;
		str = malloc((digits) * sizeof(char));
		str[0] = '-';
		n = -n;
	}
	else
		str = malloc(digits * sizeof(char));
	if (!str)
		return (0);
	while (n > 0)
	{
		str[digits--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
