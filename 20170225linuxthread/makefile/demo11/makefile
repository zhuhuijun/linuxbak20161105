.SUFFIXES: .c .o
CC=gcc
SRCS=demo11_child.c
OBJS=$(SRCS:.c=.o)
EXE=demo
all: $(OBJS)
	$(CC) -o $(EXE) $(OBJS)
	@echo '--------------OK-------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS)
	-rm -f core*	