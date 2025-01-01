void main();

void _start() {
	main();
	asm("mov $0, %dl");
	asm("mov $0, %cl");
	asm("int $0xe0");
}
