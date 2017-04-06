.SUFFIXES: .c .o
CC=gcc
SRCS=demo03_daemontest.c
OBJS=$(SRCS:.c=.o)
EXE=demod
all: $(OBJS)
	$(CC) -o $(EXE) $(OBJS)
	@echo '--------------OK-------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS)
	-rm -f core*	