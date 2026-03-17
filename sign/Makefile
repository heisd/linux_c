CC ?= gcc
CFLAGS ?= -Wall -Wextra -g
CPPFLAGS ?= -Iinclude
SRC_DIR ?= src
BIN_DIR ?= bin

SRCS := $(wildcard $(SRC_DIR)/*.c)
BINS := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.exe,$(SRCS))

.PHONY: all run clean list

all: $(BINS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%.exe: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

run: all
	@for f in $(BINS); do \
		echo "==> $$f"; \
		"$$f" || true; \
	done

clean:
	rm -f $(BIN_DIR)/*.exe

list:
	@printf '%s\n' $(BINS)
