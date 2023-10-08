/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_system_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:02 by jonask            #+#    #+#             */
/*   Updated: 2023/10/08 21:27:04 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//for now only handles positive numbers
//if number is negative it makes it positive
void put_base(int num, int base) {

	//how to handle minus?
	//just print an extra 1 infront of it when its negative?
	if(num < 0) {
		write(1, "-", 1); //for now i print a normal minus
		num = -num;
	}
	
	while (num > 0) {

		int n = (num % base);
		char c;

		if (n < 10) c = n + '0';
		else c = n + 'a';

		write(1, &c, 1);

		num /= base;

	}

}