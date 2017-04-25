.SUFFIXES: .c .o
CC=gcc
SRCS=upper.c
OBJS=$(SRCS:.c=.o)
EXE=libupper.so
all: $(OBJS)
	$(CC) -shared -o $(EXE) $(OBJS)
	@echo '--------------OK-------------'
.c.o:
	$(CC) -Wall -g -fPIC -o $@ -c $<
clean:
	-rm -f $(OBJS)
	-rm -f core*