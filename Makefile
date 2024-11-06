# Compiler
CC = gcc

# Directories
SRC_DIR = src
HELPER_DIR = helper
DATA_DIR = data
BUILD_DIR = build

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Helper files
HELPER_FILES = $(wildcard $(HELPER_DIR)/*.c)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build and run target for a specific day
run: $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(DAY) $(SRC_DIR)/$(DAY).c $(HELPER_FILES)
	$(BUILD_DIR)/$(DAY)

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: clean run