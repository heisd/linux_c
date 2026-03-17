CC ?= gcc
AR ?= ar
CFLAGS ?= -Wall -Wextra -g
CPPFLAGS ?= -Iinclude

SRC_DIR := src
OBJ_DIR := build
LIB_DIR := lib
BIN_DIR := bin
TARGET := $(BIN_DIR)/main.exe
LIB := $(LIB_DIR)/libmylib.a

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all run clean

all: $(TARGET)

$(OBJ_DIR) $(LIB_DIR) $(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIB): $(OBJS) | $(LIB_DIR)
	$(AR) rcs $@ $^

$(TARGET): main.c $(LIB) | $(BIN_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) main.c -L$(LIB_DIR) -lmylib -o $@

run: all
	$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)/libmylib.a $(TARGET)
