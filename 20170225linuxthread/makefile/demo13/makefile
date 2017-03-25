.SUFFIXES: .c .o
CC=gcc
SRCS=demo13_libso.c
OBJS=$(SRCS:.c=.o)
EXE=libtest.so
all: $(OBJS)
	$(CC) -shared -o $(EXE) $(OBJS)
	@echo '--------------OK-------------'
.c.o:
	$(CC) -Wall -g -fPIC -o $@ -c $<
clean:
	-rm -f $(OBJS)
	-rm -f core*	