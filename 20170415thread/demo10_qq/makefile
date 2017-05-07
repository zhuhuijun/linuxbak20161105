.SUFFIXES: .c .o
CC=gcc
SRCS1=client1.c
SRCS2=client2.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
EXE1=client1
EXE2=client2
all:$(OBJS1) $(OBJS2)
	$(CC) -o $(EXE1) $(OBJS1) -lpthread
	$(CC) -o $(EXE2) $(OBJS2) -lpthread
	@echo '--------------OK-------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS1)
	-rm -f $(OBJS2)
	-rm -f core*	