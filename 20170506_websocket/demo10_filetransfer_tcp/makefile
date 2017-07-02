.SUFFIXES: .c .o

CC=gcc

SERVERSRCS=server.c\
	   pub.c
CLIENTSRCS=client.c\
	   pub.c
SERVEROBJS=$(SERVERSRCS:.c=.o)
CLIENTOBJS=$(CLIENTSRCS:.c=.o)
SERVEREXEC=server
CLIENTEXEC=client

all: $(SERVEROBJS) $(CLIENTOBJS)
	$(CC) -o $(SERVEREXEC) $(SERVEROBJS)
	$(CC) -o $(CLIENTEXEC) $(CLIENTOBJS)
	@echo '^_^ ^_^ ^_^ ^_^ ^_^ ^_^ OK ^_^ ^_^ ^_^ ^_^ ^_^ ^_^'

.c.o: 
	$(CC) -Wall -g -o $@ -c $<

clean:
	-rm -f $(SERVEROBJS) 
	-rm -f $(CLIENTOBJS) 
	-rm -f core*

