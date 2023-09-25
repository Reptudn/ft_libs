#include <unistd.h>

void put_base(int num, int base) {

	//how to handle minus?

	while (num > 0) {

		int n = (num % base);
		char c;

		if (n < 10) c = n + '0';
		else c = n + 'a';

		write(1, &c, 1);

		num /= base;

	}

}