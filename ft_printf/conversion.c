/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:26:52 by jonask            #+#    #+#             */
/*   Updated: 2023/10/17 12:30:18 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_number(int num)
{
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}

	while (num > 0)
	{
		put_char((num % 10) + '0');
		num /= 10;
	}
}

void	put_long(long num)
{

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}

	while (num > 0)
	{
		put_char((num % 10) + '0');
		num /= 10;
	}
}

void	put_double(double num)
{
	double	decimal;
	int		intpart;

    if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	intpart = (int)num;
	decimal = num - intpart;
	while (intpart > 0)
	{
		put_char((intpart % 10) + '0');
		intpart /= 10;
	}
	put_char('.');
	while (decimal != 0.0)
	{

		decimal *= 10;
		put_char((int)decimal + '0');
		decimal -= (int)decimal;
	}
}

void	put_float(float num)
{
	put_double((double)num);
}

void	put_pointer(void *ptr)
{
	put_long((intptr_t)ptr);
}
