CFLAGS = -m16
OBJS = init.o hello.o

.PHONY: clean

hello.cmd: $(OBJS)
	../RetroLinker/link -F cpm86_tiny -o hello.cmd init.o hello.o

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf hello.cmd $(OBJS)
