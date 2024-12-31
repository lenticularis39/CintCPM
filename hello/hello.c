void print_char(char c);
void print_string(char *s);
void exit_prog();

void _start() {
	print_string("Hello world from GCC!");
	exit_prog();
}

void print_char(char c) {
	asm("mov $0x02, %cl");
	asm("mov %0, %%dl" : : "r"(c) :);
	asm("int $0xe0");
}

void print_string(char *s) {
	while (*s != 0)
		print_char(*s++);
}

void exit_prog() {
	asm("mov $0, %cl");
	asm("int $0xe0");
}
