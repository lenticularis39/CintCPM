void print_char(char c);
void print_string(char *s);
void exit_prog();
int fact(int i);

void _start() {
	int f;
	print_string("Happy New Year from CP/M-86 32-bit code,\r\n");
	print_string("compiled by Fedora official GCC,\r\n");
	print_string("and linked by BinaryMelodies' amazing RetroLinker!\r\n");
	print_string("By the way, factorial of 5 is:\r\n");
	f = fact(5);
	print_char('0' + f / 100);
	f -= (f / 100) * 100;
	print_char('0' + f / 10);
	f -= (f / 10) * 10;
	print_char('0' + f);
	exit_prog();
}

int fact(int i) {
	if (i == 0)
		return 1;
	else
		return i * fact(i - 1);
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
