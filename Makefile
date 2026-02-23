.PHONY: all clean

all: lint-1 Fibonacci

# Compiler
CC := gcc

# Source
SRC := Fibonacci

# Flags
CFLAGS := -Wall -Wextra -pedantic -std=c11 -O3 -c -static --save-temps

# Targets
${SRC}: ${SRC}.o
	${CC} $^ -o ${SRC}
${SRC}.o: ${SRC}.c lint-3
	${CC} $< -o $@ ${CFLAGS}
lint-3: lint-2
	clang-tidy ${SRC}.c -checks="bugprone-*" -header-filter=".*"
lint-2: lint-1
	-cpplint --verbose=5 --counting=total ${SRC}.c 
lint-1: ${SRC}.c
	cppcheck --enable=all $^

# Cleanup
clean:
	rm -rf *.o gmon* callgrind* .*.swp Fibonacci perf.data __pycache__ output.* *.s *.i
