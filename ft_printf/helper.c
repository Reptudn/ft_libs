/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:26 by jonask            #+#    #+#             */
/*   Updated: 2023/10/08 21:27:28 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "specifiers.h"
#include "ft_printf.h"

int is_specifier(char identifier, char type) {

    if (identifier != PREFIX) return 0;
    
    //i wish i ccould use a switch case here :c
    if (type == CHAR)       return CHAR;
    if (type == DECIMAL)    return DECIMAL;
    if (type == FLOAT)      return FLOAT;
    if (type == STRING)     return STRING;
    if (type == POINTER)    return POINTER;

    return 0;
}


void print_argument(void *to_print, int type) {

    if      (type == CHAR)      put_char(*(char*)to_print);
    else if (type == DECIMAL)   put_number(*(double*)to_print);
    else if (type == FLOAT)     put_float(*(float*)to_print);
    else if (type == STRING)    put_string((char*)to_print);
    else if (type == POINTER)	put_pointer(to_print);

}
