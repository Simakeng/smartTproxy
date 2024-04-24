BUILD_SCRIPTS = $(shell find . -name "*.mk")

include $(BUILD_SCRIPTS)

CC = gcc
CFLAGS =
LIBS = 

all:
	@echo "Not implemented yet..."
	@echo "see 'make help'"

dns_packet_parse: test/dns_packet_parse.c
	@echo $(BUILD_SCRIPTS)
	@echo $(SRCS)
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/dns_packet_parse.o $^
	@$(BUILD_DIR)/dns_packet_parse.o


TARGET ?= dummy

test: test/$(TARGET).c
ifeq ($(TARGET),dummy)
	@echo "No target specified! use 'make help' to see available targets"
else
	@echo "Building target $(TARGET)"
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET).o $^
	@$(BUILD_DIR)/$(TARGET).o
endif

# find all targets in test directory
TEST_TARGETS =  $(shell find ./test -name "*.c")
# exclude dummy.c from test targets
TEST_TARGETS := $(filter-out ./test/dummy.c, $(TEST_TARGETS))
# only take file name without extension
TEST_TARGETS := $(basename $(notdir $(TEST_TARGETS)))

help:
	@echo "Usage: make [target]"
	@echo "┌──────┐"
	@echo "| Test |"
	@echo "└──────┘"
	@echo "Usage: make test TARGET=<test_name>"
	@echo "Available tests:"
# print with new line and add prefix -
	@$(foreach target,$(TEST_TARGETS),echo "  - $(target)";)
