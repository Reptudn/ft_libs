#ifndef FT_PRINTF_H
#define FT_PRINTF_H

//helper.c
int is_specifier(char identifier, char type);

//conversion.c
void put_string(char *str);
void put_char(char c);
void put_number(int num);
void put_double(double num);
void put_float(float num);
void put_pointer(void *ptr);

#endif