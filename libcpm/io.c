#include <cpm.h>

void print_char(char c) {
	asm("mov $0x02, %cl");
	asm("mov %0, %%dl" : : "r"(c) :);
	asm("int $0xe0");
}

void print_string(char *s) {
	while (*s != 0)
		print_char(*s++);
}

void exit_prog(char abort_code) {
	asm("mov %0, %%dl" : : "r"(abort_code) :);
	asm("mov $0, %cl");
	asm("int $0xe0");
}
