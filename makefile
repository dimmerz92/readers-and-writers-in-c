COMPILER = gcc
CFLAGS = -Wall -pedantic -pthread
COBJS = main.o reader.o writer.o join_threads.o
CEXES = main

all: ${CEXES}

%.o: %.c headers.h makefile
	${COMPILER} ${CFLAGS} -c $< -o $@

${CEXES}: ${COBJS}
	${COMPILER} ${CFLAGS} ${COBJS} -o ${CEXES}

clean:
	rm -f *.o *~ ${CEXES}