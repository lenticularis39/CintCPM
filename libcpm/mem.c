#include <cpm.h>

char get_maximum_memory(struct mcb *m) {
	char retval;

	asm volatile(
	"mov $0x35, %%cl\n\t"
	"mov %1, %%edx\n\t"
	"int $0xe0\n\t"
	"mov %%al, %0"
	: "=m"(retval) : "r"(m) :);
	
	return retval;
}

char allocate_memory(struct mcb *m) {
	char retval;

	asm volatile(
	"mov $0x37, %%cl\n\t"
	"mov %1, %%edx\n\t"
	"int $0xe0\n\t"
	"mov %%al, %0"
	: "=m"(retval) : "r"(m) :);
	
	return retval;
}

char free_memory(struct mcb *m) {
	char retval;

	asm volatile(
	"mov $0x39, %%cl\n\t"
	"mov %1, %%edx\n\t"
	"int $0xe0\n\t"
	"mov %%al, %0"
	: "=m"(retval) : "r"(m) :);
	
	return retval;
}
