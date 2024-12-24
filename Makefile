.PHONY: all clean

all: format-check Fibonacci

# Compiler
CC := gcc

# Includes
INCL := lib/CircularQueue

# Source
SRC := Fibonacci

# Flags
CFLAGS := -Wall -Wextra -pedantic -std=c11 -O3 -c -g -Ilib

# Targets
${SRC}: ${SRC}.o ${INCL}.o
	${CC} $^ -o ${SRC}
${SRC}.o: ${SRC}.c
	${CC} $< -o $@ ${CFLAGS}
${INCL}.o: ${INCL}.c
	${CC} $< -o $@ ${CFLAGS}
format-check: ${SRC}.c ${INCL}.c
	cppcheck --enable=all $^

# Cleanup
clean:
	rm -rf *.o gmon* callgrind* .*.swp Fibonacci perf.data ./lib/*.o ./lib/CircularQueue
