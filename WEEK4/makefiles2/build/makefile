# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -g

# Directories
SRC_DIR1 = ../folder1
SRC_DIR2 = ../folder2
BUILD_DIR = .  # Store compiled object files in the current directory

# Target executable
TARGET = output

# Source and Object Files
SRC = $(wildcard $(SRC_DIR1)/*.c) $(wildcard $(SRC_DIR2)/*.c)  # Find all .c files
OBJ = $(patsubst %.c, %.o, $(notdir $(SRC)))  # Convert .c to .o (store in BUILD_DIR)

# Build executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile .c to .o
%.o: $(SRC_DIR1)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(SRC_DIR2)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)

