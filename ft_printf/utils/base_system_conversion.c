/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_system_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:02 by jonask            #+#    #+#             */
/*   Updated: 2023/10/23 09:22:21 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	write_base(char base_buff[], int len, int *writecount)
{
	int	i;

	i = 20 - len;
	put_string("0x", writecount);
	while (i < 20 && *writecount != 1)
	{
		if (base_buff[i] == 'a')
		{
			i++;
			continue ;
		}
		if (write(1, &base_buff[i], 1) == -1)
			*writecount = -1;
		else
			*writecount += 1;
		i++;
	}
}

// is printing them in the wrong order instead of 2A its printing A2
void	put_base(long num, int base, int capital, int *writecount)
{
	char	c;
	int		n;
	char	buff[20];
	int		i;

	i = 19;
	if (num < 0)
		num = -num;
	//memset everything to 'a'
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
		buff[i--] = c;
		num /= base;
	}
	write_base(buff, i, writecount);
}
