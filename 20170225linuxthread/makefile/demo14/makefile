.SUFFIXES: .c .o
CC=gcc
SRCS=testlib.c
OBJS=$(SRCS:.c=.o)
EXE=demo
all: $(OBJS)
	$(CC) -L. -ltest -o $(EXE) $(OBJS)
	@echo '--------------OK-------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS)
	-rm -f core*	