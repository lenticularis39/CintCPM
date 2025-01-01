CFLAGS = -m16
SRCS = init.c

all: libcpm.o

.PHONY: clean

libcpm.o: libcpm.c

libcpm.c: $(SRCS)
	cat $(SRCS) > libcpm.c

clean:
	rm -rf libcpm.o libcpm.c
