/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_system_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:02 by jonask            #+#    #+#             */
/*   Updated: 2023/10/18 09:45:28 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//for now only handles positive numbers
//if number is negative it makes it positive

void	put_base(long num, int base, int capital)
{
	char	c;
	int		n;

	if (num < 0)
		num = -num;
	while (num > 0)
	{
		n = (num % base);
		if (n < 10)
			c = n + '0';
		else
		{
			if (capital)
				c = n + 'A';
			else
				c = n + 'a';
		}
		write(1, &c, 1);
		num /= base;
	}
}
