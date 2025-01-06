#pragma once

void print_char(char c);
void print_string(char *s);
void read_line(char *buffer, unsigned char len);
void exit_prog(char abort_code);

struct mcb {
    unsigned short base;
    unsigned short length;
    unsigned char ext;
} __attribute__((packed));

char get_maximum_memory(struct mcb *m);
char allocate_memory(struct mcb *m);
char free_memory(struct mcb *m);
