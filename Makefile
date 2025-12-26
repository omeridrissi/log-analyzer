# ===== Project settings =====
PROJECT_NAME := log-analyzer
CC           := gcc

# ===== Directories =====
SRC_DIR  := src
INC_DIR  := include
OBJ_DIR  := build/obj
BIN_DIR  := build/bin

# ===== Compiler flags =====
CFLAGS  := -Wall -Wextra -Werror -std=c11 -I$(INC_DIR)
LDFLAGS :=

# ===== Source files =====
SRCS := $(shell find $(SRC_DIR) -name '*.c')

# Convert src/foo/bar.c → build/obj/foo/bar.o
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ===== Output =====
TARGET := $(BIN_DIR)/$(PROJECT_NAME)

# ===== Default rule =====
all: $(TARGET)

# ===== Link =====
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# ===== Compile =====
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ===== Utility targets =====
clean:
	rm -rf build

run: all
	./$(TARGET)

debug: CFLAGS += -g
debug: clean all

.PHONY: all clean run debug

