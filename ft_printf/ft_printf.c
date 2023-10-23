/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:09 by jonask            #+#    #+#             */
/*   Updated: 2023/10/23 09:42:37 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/specifiers.h"
#include "ft_printf.h"

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list		keys;
	int			i;
	int			specifier_index;
	int			argcount;
	int			writecount;

	argcount = 0;
	writecount = 0;
	va_start(keys, str);
	i = 0;
	while (str[i] != 0)
	{
		if (writecount == -1)
			return (-1);
		specifier_index = is_specifier(str[i], str[i + 1]);
		if (str[i + 1] != 0 && str[i + 1] == '%' && str[i] == '%')
		{
			put_char('%', &writecount);
			i += 2;
			continue ;
		}
		else if (str[i + 1] != 0 && specifier_index > 0)
		{
			if (argcount >= count_args(str))
				return (-1);
			i += 2;
			print_argument(&keys, specifier_index, &writecount);
			argcount++;
			continue ;
		}
		if (str[i] != 0)
			put_char(str[i++], &writecount);
	}
	va_end(keys);
	return (writecount);
}

/*
not working yet:
%u - max/min values
%i - max/min values
just make it a long

working:
%c
%s
*/

// int	main(void)
// {
// 	int	i;
// 	// int	og;

// 	i = ft_printf("%d", -10);
// 	ft_printf("\n---------\n\n");
// 	// og = printf("Test Char: %c\nInt max: %i\nInt min: %li\nString: %s\nHex: %X\n", 'u', 2147483647, -2147483648, "42 Helbronn", 42);
// 	if (i == -1)
// 		ft_printf("error: %d", i);
// 	ft_printf("\n---------\n\n");
// 	ft_printf("[MY] Num of chars printed: %d\n", i);
// 	// printf("[OG] Num of chars printed: %d\n", og);
// }
