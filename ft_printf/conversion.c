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

    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }

    while (num > 0) {

        put_char((num % 10) + '0');
        num /= 10;

    }

}

void put_long(long num) {

    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }

    while (num > 0) {

        put_char((num % 10) + '0');
        num /= 10;

    }

}

void put_double(double num) {

    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }

}

void put_float(float num) {

    if (num < 0) {
        write(1, "-", 1);
        num = -num;
    }

}

void put_pointer(void *ptr) {

    put_long((intptr_t)ptr);

}