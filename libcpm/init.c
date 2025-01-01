#define STACK_LEN 256

void main();

char stack[STACK_LEN];

void _start() {
	asm volatile(
	"mov %0, %%esp\n\t"
	"mov %%cs, %%bx\n\t"
	"mov %%bx, %%ss"
	: : "r"(stack + STACK_LEN - 1)
	: "%bx");
	main();
	asm volatile(
	"mov $0, %dl\n\t"
	"mov $0, %cl\n\t"
	"int $0xe0"
	);
}
