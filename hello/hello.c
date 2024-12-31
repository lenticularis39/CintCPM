void _start() {
	for (int i = 0; i < 1000000; i++);
	asm("mov $0, %ecx");
	asm("int $0xe0");
}
