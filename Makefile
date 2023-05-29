# # Compiler
# CC := clang

# # Directories
# SRC_DIR := src
# BIN_DIR := bin

# # Source files
# SRCS := $(wildcard $(SRC_DIR)/*.c)

# # Object files
# OBJS := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SRCS))

# # Binary name
# TARGET := mybinary

# # Default target
# all: $(BIN_DIR)/$(TARGET)

# # Rule to create the binary
# $(BIN_DIR)/$(TARGET): $(OBJS)
# 	$(CC) $^ -o $@

# # Rule to create object files
# $(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
# 	$(CC) -c $< -o $@

# # Rule to create the bin directory
# $(BIN_DIR):
# 	mkdir -p $(BIN_DIR)

# # Clean rule
# clean:
# 	rm -rf $(BIN_DIR)

# .PHONY: all clean
