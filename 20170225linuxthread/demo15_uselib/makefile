.SUFFIXES: .cpp .o
CC=g++
SRCS=testlib.cpp
OBJS=$(SRCS:.cpp=.o)
EXE=demo
all: $(OBJS)
	$(CC) -L. -ltest -o $(EXE) $(OBJS)
	@echo '--------------OK-------------'
.cpp.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	-rm -f $(OBJS)
	-rm -f core*	