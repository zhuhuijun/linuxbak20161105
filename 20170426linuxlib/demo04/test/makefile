.SUFFIXES: .c .o
CC=gcc
SRCS=demo01_testlib.c
OBJS=$(SRCS:.c=.o)
EXE=demo
all: $(OBJS)
	$(CC) -L. -lupper -o $(EXE) $(OBJS)
	@echo '--------------OK-------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS)
	-rm -f core*