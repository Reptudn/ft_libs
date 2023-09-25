#include <stdio.h>
#include <stdarg.h>

#include "specifiers.h"
#include "ft_printf.h"

#include <stdio.h>

// variable amount of arguments
// https://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm

// printf stuff
// https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm



void ft_printf(char *str, int count, ...) {

    va_list keys;
    va_start(keys, count);

    int i = 0;
    int param_index = 0;

    if (count <= 0) {
        put_string(str);
        return;
    }

    while(str[i] != 0) {

        int specifier_index = 0;
        specifier_index = is_specifier(str[i], str[i+1]);

        if(str[i + 1] != 0 && specifier_index > 0) {

            print_argument(va_arg(keys, void*), specifier_index);

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

    char *str = "Test Message %d,pog";
    int count = 3;

    ft_printf(str, count, 13, 'c', "banana");

}