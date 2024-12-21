# Compiler
CC := gcc

# Flags
CFLAGS := -Wall -Wextra -pedantic -std=c17 -O3 -c

Fibonacci: Fibonacci.o
	${CC} $< -o $@
Fibonacci.o: Fibonacci.c
	${CC} $< -o $@ ${CFLAGS}

# Cleanup
clean:
	rm -rf *.o gmon* callgrind* .*.swp Fibonacci 
