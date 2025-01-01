#include <cpm.h>

void print_char(char c) {
	asm volatile(
	"mov $0x02, %%cl\n\t"
	"mov %0, %%dl\n\t"
	"int $0xe0"
	: : "r"(c) :);
}

void print_string(char *s) {
	while (*s != 0)
		print_char(*s++);
}

void read_line(char *buffer, unsigned char len) {
	int n;
	buffer[0] = buffer[1] = len - 1;

	asm volatile(
	"mov %0, %%edx\n\t"
	"mov $0x0a, %%cl\n\t"
	"int $0xe0"
	: : "r"(buffer) :);
	n = buffer[1];

	print_char('\n');
	for (int i = 0; i < n; i++) {
		buffer[i] = buffer[i + 2];
	}
	buffer[n] = '\0';
}

void exit_prog(char abort_code) {
	asm volatile(
	"mov %0, %%dl\n\t"
	"mov $0, %%cl\n\t"
	"int $0xe0"
	: : "r"(abort_code) :);
}
