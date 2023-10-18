/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:09 by jonask            #+#    #+#             */
/*   Updated: 2023/10/18 09:30:26 by jkauker          ###   ########.fr       */
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
		if (str[i + 1] != 0 && str[i + 1] == '%' && str[i] == '%')
		{
			write(1, "%%", 2);
			i++;
			continue ;
		}
		else if (str[i + 1] != 0 && specifier_index > 0)
		{
			print_argument(&keys, specifier_index);
			param_index++;
			i += 2;
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
