CFLAGS = -m16
CPPFLAGS = -I../include
OBJS = tree.o

.PHONY: clean

tree.cmd: $(OBJS) ../libcpm/libcpm.o
	../RetroLinker/link -F cpm86_tiny -o tree.cmd ../libcpm/libcpm.o ../libutil/libutil.o tree.o

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf tree.cmd $(OBJS)
