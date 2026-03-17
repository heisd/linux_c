CC ?= gcc
CFLAGS ?= -Wall -Wextra -g -fPIC
CPPFLAGS ?= -Iinclude

SRC_DIR := src
OBJ_DIR := build
LIB_DIR := lib
BIN_DIR := bin
SO := $(LIB_DIR)/libmyshared.so
TARGET := $(BIN_DIR)/main.exe

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all run clean

all: $(TARGET)

$(OBJ_DIR) $(LIB_DIR) $(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(SO): $(OBJS) | $(LIB_DIR)
	$(CC) -shared -o $@ $^

$(TARGET): main.c $(SO) | $(BIN_DIR)
	$(CC) $(CPPFLAGS) -Wall -Wextra -g main.c -L$(LIB_DIR) -lmyshared -Wl,-rpath,'$$ORIGIN/../lib' -o $@

run: all
	$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(SO) $(TARGET)
