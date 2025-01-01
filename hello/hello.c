#include <cpm.h>

#define BUFFER_MAX 32

char buffer[BUFFER_MAX];

int fact(int i);

void main() {
	int f;

	print_string("What's your name?\r\n");
	read_line(buffer, BUFFER_MAX);

	print_string("Happy New Year ");
	print_string(buffer);
	print_string(" from CP/M-86 32-bit code,\r\n");
	print_string("compiled by Fedora official GCC,\r\n");
	print_string("and linked by BinaryMelodies' amazing RetroLinker!\r\n");
	print_string("By the way, factorial of 5 is:\r\n");
	f = fact(5);
	print_char('0' + f / 100);
	f -= (f / 100) * 100;
	print_char('0' + f / 10);
	f -= (f / 10) * 10;
	print_char('0' + f);
}

int fact(int i) {
	if (i == 0)
		return 1;
	else
		return i * fact(i - 1);
}

