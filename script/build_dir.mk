PROJ_ROOT=$(shell pwd)

# Directory for build files
BUILD_DIR=$(PROJ_ROOT)/build

# Directory for source files
SRC_DIR=$(PROJ_ROOT)/src

# All source files
SRCS=$(shell find $(SRC_DIR) -name "*.c")

# All object files
OBJS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))