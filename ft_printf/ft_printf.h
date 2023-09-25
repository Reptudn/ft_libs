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
void put_base(int num, int base);

#endif