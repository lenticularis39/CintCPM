#include <cpm.h>

struct mcb {
	unsigned short base;
	unsigned short length;
	unsigned char ext;
} __attribute__((packed));

static char _get_maximum_memory(struct mcb *m) {
	char retval;

	asm volatile(
	"mov $0x35, %%cl\n\t"
	"mov %1, %%edx\n\t"
	"int $0xe0\n\t"
	"mov %%al, %0"
	: "=m"(retval) : "r"(m) :);
	
	return retval;
}

static char _allocate_memory(struct mcb *m) {
	char retval;

	asm volatile(
	"mov $0x37, %%cl\n\t"
	"mov %1, %%edx\n\t"
	"int $0xe0\n\t"
	"mov %%al, %0"
	: "=m"(retval) : "r"(m) :);
	
	return retval;
}

static char _free_memory(struct mcb *m) {
	char retval;

	asm volatile(
	"mov $0x39, %%cl\n\t"
	"mov %1, %%edx\n\t"
	"int $0xe0\n\t"
	"mov %%al, %0"
	: "=m"(retval) : "r"(m) :);
	
	return retval;
}

