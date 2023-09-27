#include <unistd.h>

//for now only handles positive numbers
//if number is negative it makes it positive
void put_base(int num, int base) {

	//how to handle minus?
	//just print an extra 1 infront of it when its negative?

	if(num < 0) num = -num;

	while (num > 0) {

		int n = (num % base);
		char c;

		if (n < 10) c = n + '0';
		else c = n + 'a';

		write(1, &c, 1);

		num /= base;

	}

}