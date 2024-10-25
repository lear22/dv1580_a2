# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -fPIC

# Directories
SRC_DIR = .
BIN_DIR = .

# Source files
SRCS = memory_manager.c linked_list.c main.c test_linked_list.c test_memory_manager.c
OBJS = $(SRCS:.c=.o)

# Libraries
LIBS = -lpthread -lm

# Binaries
EXEC_LINKED_LIST_APP = linked_list_app
EXEC_TEST_LINKED_LIST = test_linked_list
EXEC_TEST_MEMORY_MANAGER = test_memory_manager
SHARED_LIB = libmemory_manager.so

# Targets
all: $(EXEC_LINKED_LIST_APP) $(EXEC_TEST_LINKED_LIST) $(EXEC_TEST_MEMORY_MANAGER) $(SHARED_LIB)

# Build shared library
$(SHARED_LIB): memory_manager.o
	$(CC) -shared -o $@ $^

# Build linked list application
$(EXEC_LINKED_LIST_APP): main.o linked_list.o
	$(CC) -o $@ $^ -I. -L. -lmemory_manager $(LIBS)

# Build test linked list
$(EXEC_TEST_LINKED_LIST): test_linked_list.o linked_list.o
	$(CC) -o $@ $^ -I. -L. -lmemory_manager $(LIBS)

# Build test memory manager
$(EXEC_TEST_MEMORY_MANAGER): test_memory_manager.o memory_manager.o
	$(CC) -o $@ $^ $(LIBS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC_LINKED_LIST_APP) $(EXEC_TEST_LINKED_LIST) $(EXEC_TEST_MEMORY_MANAGER) $(SHARED_LIB)

.PHONY: all clean
