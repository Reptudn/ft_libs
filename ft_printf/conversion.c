# include <unistd.h>

void put_string(char *str) {

    int i = 0;

    while (str[i] != 0) {
        write(1, &str[i], 1);
        i++;
    }

}

void put_char(char c) {
    write(1, &c, 1);
}

void put_number(int num) {

}

void put_double(double num) {

}

void put_float(float num) {

}