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

void read_line(char *buffer, unsigned char len) {
	int n;
	buffer[0] = buffer[1] = len - 1;

	asm("mov %0, %%edx" : : "r"(buffer) :);
	asm("mov $0x0a, %cl");
	asm("int $0xe0");
	n = buffer[1];

	for (int i = 0; i < n; i++) {
		buffer[i] = buffer[i + 2];
	}
	buffer[n] = '\0';
}

void exit_prog(char abort_code) {
	asm("mov %0, %%dl" : : "r"(abort_code) :);
	asm("mov $0, %cl");
	asm("int $0xe0");
}
