/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonask <jonask@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:27:09 by jonask            #+#    #+#             */
/*   Updated: 2023/10/12 08:37:28 by jonask           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"
#include "ft_printf.h"

/*
variable amount of arguments
https://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm

printf stuff
https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

=> TYPES I HAVE TO HANDLE: cspdiuxX%

cc ft_printf.c ft_printf.h conversion.c base_system_conversion.c helper.c specifiers.h

What if the arguments are not in correcct order and i handle a string as int?
-> gotta check for that and handle it
*/

//remove the count and figure out how it works without the count
int ft_printf(char *str, int count, ...) {

    va_list keys; //this makes err?
    va_start(keys, count);

    int i = 0;
    int param_index = 0;

    if (count <= 0) {
        put_string(str);
        return (1);
    }

    while(str[i] != 0) {

        int specifier_index = 0;
        specifier_index = is_specifier(str[i], str[i + 1]);

        if (str[i + 1] != 0 && str[i + 1] == '%')
            write(1, "%%", 1);
        else if(str[i + 1] != 0 && specifier_index > 0) {

            printf("   va_arg: %s\n", va_arg(keys, char*));
            print_argument(va_arg(keys, void *), specifier_index);

            param_index++;
            i += 2;
            continue;
        }

        put_char(str[i]);

        i++;
    }

    va_end(keys);

}

//testing main func
int main(void) {

    int count = 3;

    ft_printf("Test \nMessage %d,pog %c%s\n", count, 13, 'c', "banana");

}