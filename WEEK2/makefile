# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -g

# Target Executable
TARGET = program

# Rule to build the executable
$(TARGET): mat_multiplication.o
	$(CC) $(CFLAGS) -o $(TARGET) mat_multiplication.o

# Rule to compile mat_multiplication.c into mat_multiplication.o
mat_multiplication.o: mat_multiplication.c
	$(CC) $(CFLAGS) -c mat_multiplication.c -o mat_multiplication.o

# Clean rule
clean:
	rm -f $(TARGET) *.o

