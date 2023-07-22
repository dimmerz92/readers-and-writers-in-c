COMPILER = gcc
CFLAGS = -Wall -pedantic -pthread
CEXES = main

all: ${CEXES}

clean:
	rm -f *.o *~ ${CEXES}