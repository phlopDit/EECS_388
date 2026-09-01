CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g

SRC_DIR = src
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/p*.c)
PROGRAMS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.exe,$(SOURCES))

all: $(PROGRAMS)

$(BUILD_DIR)/%.exe: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.exe