#include <cpm.h>
#include <limits.h>
#include <stdbool.h>

#define BUFFER_MAX 128

static char buffer[BUFFER_MAX];

int string_to_int(char *s) {
	int i = 0;
	while (*s >= '0' && *s <= '9') {
		i = i * 10;
		i = i + (*s - '0');
	s++;
	}
	return i;
}

void int_to_string(int i, char *s) {
	int len, j;
	
	if (i == 0) {
		s[0] = '0';
		s[1] = '\0';
		return;
	}
	
	if (i < 0 && i != INT_MIN) {
		s[0] = '-';
		int_to_string(-i, s + 1);
		return;
	}
	
	if (i < 0 && i == INT_MIN) {
		int_to_string(INT_MIN + 1, s);
		s[10] = '8';
		return;
	}
	
	j = i;
	len = 0;
	while (j != 0) {
		j /= 10;
		len++;
	}
	for (j = len - 1; j >= 0; j--) {
		s[j] = '0' + (i % 10);
		i /= 10;
	}
	s[len] = '\0';
}

bool strings_equal(char *a, char *b) {
	while (*a != '\0' && *b != '\0') {
		if (*a++ != *b++)
			return false;
	}

	return *a == *b;
}

int read_number() {
	read_line(buffer, BUFFER_MAX);
	return string_to_int(buffer);
}

void print_number(int i) {
	int_to_string(i, buffer);
	print_string(buffer);
}
