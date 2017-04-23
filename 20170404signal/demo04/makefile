.SUFFIXES: .c .o
CC=gcc
SRCS1=readd2.c
SRCS2=writed.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
EXE1=myreadd
EXE2=mywrite
all: $(OBJS1) $(OBJS2)
	$(CC) -o $(EXE1) $(OBJS1)
	$(CC) -o $(EXE2) $(OBJS2)
	@echo '--------------OK-------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS1)
	-rm -f $(OBJS2)
	-rm -f core*	