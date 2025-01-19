.PHONY: all clean

all: format-check Fibonacci

# Compiler
CC := gcc

# Source
SRC := Fibonacci

# Flags
CFLAGS := -Wall -Wextra -pedantic -std=c11 -O3 -c

# Targets
${SRC}: ${SRC}.o
	${CC} $^ -o ${SRC}
${SRC}.o: ${SRC}.c
	${CC} $< -o $@ ${CFLAGS}
format-check: ${SRC}.c
	cppcheck --enable=all $^

# Cleanup
clean:
	rm -rf *.o gmon* callgrind* .*.swp Fibonacci perf.data
