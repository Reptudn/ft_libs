/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_system_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:02 by jonask            #+#    #+#             */
/*   Updated: 2023/10/20 11:00:52 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

// is printing them in the wrong order instead of 2A its printing A2
void	put_base(long num, int base, int capital, int *writecount)
{
	char	c;
	int		n;

	if (num < 0)
		num = -num;
	while (num > 0 && *writecount != -1)
	{
		n = (num % base);
		if (n < 10)
			c = n + '0';
		else
		{
			if (capital)
				c = n + 'A';
			else
				c = n - 10 + 'a';
		}
		if (write(1, &c, 1) == -1)
			*writecount = -1;
		else
			*writecount += 1;
		num /= base;
	}
}
