CFLAGS = -m16
CPPFLAGS = -I../include
OBJS = hello.o

.PHONY: clean

hello.cmd: $(OBJS) ../libcpm/libcpm.o
	../RetroLinker/link -F cpm86_tiny -o hello.cmd ../libcpm/libcpm.o hello.o

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf hello.cmd $(OBJS)
