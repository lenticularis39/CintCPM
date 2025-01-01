CFLAGS = -m16
CPPFLAGS = -I../include
SRCS = init.c io.c

all: libcpm.o

.PHONY: clean

libcpm.o: libcpm.c

libcpm.c: $(SRCS)
	cat $(SRCS) > libcpm.c

clean:
	rm -rf libcpm.o libcpm.c
