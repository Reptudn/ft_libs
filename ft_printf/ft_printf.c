/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:09 by jonask            #+#    #+#             */
/*   Updated: 2023/10/18 09:22:08 by jkauker          ###   ########.fr       */
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
	int			param_index;
	int			specifier_index;
	va_list		keys;

	va_start(keys, str);
	i = 0;
	param_index = 0;
	while (str[i] != 0)
	{
		specifier_index = is_specifier(str[i], str[i + 1]);
		printf("\nspecifier_index: %d\n", specifier_index);
		if (str[i + 1] != 0 && str[i + 1] == '%')
		{
			write(1, "%%", 2);
			i += 2;
			continue ;
		}
		else if (str[i + 1] != 0 && specifier_index > 0)
		{
			print_argument(&keys, specifier_index);
			param_index++;
			i += 3;
			continue ;
		}
		put_char(str[i]);
		i++;
	}
	va_end(keys);
	return (i);
}

int	main(void)
{
	ft_printf("Test Message %c,pog %s\n", 'u', "banana");
}
