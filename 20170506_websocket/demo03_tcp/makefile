.SUFFIXES: .c .o
CC=gcc
SRCS=demo.c
SRCS2=server.c
OBJS=$(SRCS:.c=.o)
OBJS2=$(SRCS2:.c=.o)
EXE=demo
EXE2=server
all: $(OBJS) $(OBJS2)
	$(CC) -o $(EXE) $(OBJS) -lpthread
	$(CC) -o $(EXE2) $(OBJS2) -lpthread
	@echo '--------------OK-------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS)
	-rm -f $(OBJS2)
	-rm -f core*	