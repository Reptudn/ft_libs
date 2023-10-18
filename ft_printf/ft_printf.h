/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:17 by jonask            #+#    #+#             */
/*   Updated: 2023/10/18 09:54:32 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/_types/_va_list.h>

//helper.c
int		is_specifier(char identifier, char type);
void	print_argument(va_list *to_print, int type);
int		count_args(const char *str);

//conversion.c
void	put_string(char *str);
void	put_char(char c);
void	put_number(int num);
void	put_long(long num);
void	put_double(double num);
void	put_float(float num);
void	put_pointer(void *ptr);

//base_system_conversion.c
void	put_base(int num, int base, int capital);

#endif