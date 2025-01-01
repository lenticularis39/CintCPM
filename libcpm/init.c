void main();

void _start() {
	main();
	asm volatile(
	"mov $0, %dl\n\t"
	"mov $0, %cl\n\t"
	"int $0xe0"
	);
}
