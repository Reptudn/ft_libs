#include <stdio.h>
#include <stdarg.h>

#include "specifiers.h"

#include <stdio.h>

// variable amount of arguments
// https://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm

// printf stuff
// https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

void ft_printf(char *str, int count, ...) {

    va_list keys;
    va_start(keys, count);

    

    va_end(keys);

}

int main(void) {

    char *str = "Test Message %d";
    int count = 3;

    ft_printf(str, count, 13, 'c', "banana");

}