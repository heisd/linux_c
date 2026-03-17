CC ?= gcc
CFLAGS ?= -Wall -Wextra -g
CPPFLAGS ?= -Iinclude
SRC_DIR := src
BIN_DIR := bin

SRCS := $(SRC_DIR)/main.c $(SRC_DIR)/add.c $(SRC_DIR)/sub.c $(SRC_DIR)/mul.c $(SRC_DIR)/div.c
TARGET := $(BIN_DIR)/calculator.exe

.PHONY: all run clean

all: $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(TARGET): $(SRCS) | $(BIN_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SRCS) -o $@

run: all
	$(TARGET)

clean:
	rm -f $(TARGET)
