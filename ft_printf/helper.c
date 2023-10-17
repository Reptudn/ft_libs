/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:26 by jonask            #+#    #+#             */
/*   Updated: 2023/10/17 12:35:43 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "specifiers.h"
#include "ft_printf.h"

int is_specifier(char identifier, char type) {

    if (identifier != PREFIX) return 0;
    
    //i wish i ccould use a switch case here :c
    if (type == CHAR)       return CHAR;
    if (type == STRING)     return STRING;
    if (type == DECIMAL)    return DECIMAL;
    if (type == POINTER)    return POINTER;
    if (type == INTEGER)    return INTEGER;
    if (type == UINTEGER)   return UINTEGER;
    if (type == HEXSMALL)   return HEXSMALL;
    if (type == HEXBIG) return HEXBIG;
    //add more

    return 0;
}

void	print_argument (void *to_print, int type)
{
    if (type == CHAR)
		put_char(*(char *)to_print);
    else if (type == STRING)
		put_string((char *)to_print);
    else if (type == POINTER)
		put_pointer(to_print);
    else if (type == DECIMAL)
		put_number(*(double *)to_print);
    else if (type == INTEGER)
		put_number(*(int *)to_print);
    else if (type == UINTEGER)
		put_number(*(int *)to_print);
    else if (type == HEXBIG)
		put_base(*(int *)to_print, 16, 1);
    else if (type == HEXSMALL)
		put_base(*(int *)to_print, 16, 0);
}
