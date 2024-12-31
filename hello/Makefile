CFLAGS = -m16

.PHONY: clean

hello.cmd: hello.o
	../RetroLinker/link -F cpm86_tiny -o hello.cmd hello.o

hello.o: hello.c

clean:
	rm -rf hello.cmd hello.o
