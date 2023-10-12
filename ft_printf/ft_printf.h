/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:17 by jonask            #+#    #+#             */
/*   Updated: 2023/10/12 09:49:52 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

//helper.c
int is_specifier(char identifier, char type);
void print_argument(void *to_print, int type);
	
//conversion.c
void put_string(char *str);
void put_char(char c);
void put_number(int num);
void put_long(long num);
void put_double(double num);
void put_float(float num);
void put_pointer(void *ptr);

//base_system_conversion.c
void put_base(int num, int base, int capital);

#endif