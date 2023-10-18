/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:17 by jonask            #+#    #+#             */
/*   Updated: 2023/10/18 10:27:19 by jkauker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/_types/_va_list.h>

//helper.c
int		is_specifier(char identifier, char type);
void	print_argument(va_list *to_print, int type, int	*writecount);
int		count_args(const char *str);
long	reverse_num(unsigned long num);

//conversion.c
void	put_string(char *str, int *writecount);
void	put_char(char c, int *writecount);
void	put_number(int num, int *writecount);
void	put_long(long num, int *writecount);
void	put_double(double num, int *writecount);
void	put_float(float num, int *writecount);
void	put_pointer(void *ptr, int *writecount);

//base_system_conversion.c
void	put_base(long num, int base, int capital, int *writecount);

#endif