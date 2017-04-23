.SUFFIXES: .c .o
CC=gcc
SRCS=demo01_thread.c
OBJS=$(SRCS:.c=.o)
EXE=demo
all: $(OBJS)
	$(CC) -o $(EXE) $(OBJS) -lpthread
	@echo '--------------OK-------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS)
	-rm -f core*	