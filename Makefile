.PHONY: all clean

all: format-check-1 Fibonacci

# Compiler
CC := gcc

# Source
SRC := Fibonacci

# Flags
CFLAGS := -Wall -Wextra -pedantic -std=c11 -O3 -c -static

# Targets
${SRC}: ${SRC}.o
	${CC} $^ -o ${SRC}
${SRC}.o: ${SRC}.c format-check-2
	${CC} $< -o $@ ${CFLAGS}
format-check-2: format-check-1
	-cpplint --verbose=5 --counting=total ${SRC}.c 
format-check-1: ${SRC}.c
	cppcheck --enable=all $^

# Cleanup
clean:
	rm -rf *.o gmon* callgrind* .*.swp Fibonacci perf.data __pycache__ output.*
