.SUFFIXES: .c .o
CC=gcc
SRCS1=a.c
SRCS2=b.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)	
EXE1=a
EXE2=b
all: $(OBJS1) $(OBJS2)
	$(CC) -o $(EXE1) $(OBJS1)
	$(CC) -o $(EXE2) $(OBJS2)
	@echo '--------------OK-------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS1)
	-rm -f core*	