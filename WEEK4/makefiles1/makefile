# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -g

# Target executable
TARGET = output

# Source and Object Files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Build executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f *.o  $(TARGET)

