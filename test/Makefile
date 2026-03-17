CC ?= gcc
CFLAGS ?= -Wall -Wextra -g
TARGET := bin/test.exe

.PHONY: all run clean

all: $(TARGET)

bin:
	mkdir -p bin

$(TARGET): test.c | bin
	$(CC) $(CFLAGS) $< -o $@

run: all
	$(TARGET)

clean:
	rm -f $(TARGET)
