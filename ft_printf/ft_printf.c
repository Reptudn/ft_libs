/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:09 by jonask            #+#    #+#             */
/*   Updated: 2023/10/18 09:59:15 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"
#include "ft_printf.h"

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	int			i;
	int			specifier_index;
	va_list		keys;
	int			argcount;

	argcount = 0;
	va_start(keys, str);
	i = 0;
	while (str[i] != 0)
	{
		specifier_index = is_specifier(str[i], str[i + 1]);
		if (str[i + 1] != 0 && str[i + 1] == '%' && str[i] == '%')
		{
			write(1, "%", 1);
			i++;
			continue ;
		}
		else if (str[i + 1] != 0 && specifier_index > 0)
		{
			i += 2;
			if (argcount <= count_args(str))
			{
				print_argument(&keys, specifier_index);
				argcount++;
				continue ;
			}
		}
		if (str[i] != 0)
			put_char(str[i++]);
	}
	va_end(keys);
	return (i);
}

int	main(void)
{
	int	i;

	i = 42;
	ft_printf("Test Message %c ,pog %s?apple\n", 'u', "banana", 42, &i);
}
