/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_system_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:02 by jonask            #+#    #+#             */
/*   Updated: 2023/10/12 09:43:54 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//for now only handles positive numbers
//if number is negative it makes it positive
void put_base(int num, int base, int capital) {

	if(num < 0) {
		num = -num;
	}
	
	while (num > 0) {

		int n = (num % base);
		char c;

		if (n < 10) c = n + '0';
		else
		{
			if (capital) c = n + 'A';
			else c = n + 'a';
		}

		write(1, &c, 1);

		num /= base;

	}

}