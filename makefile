# Compiler and flags
CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared
LINK_FLAGS = -L. -lmemory_manager

# File paths and names
MEMORY_MANAGER_SRC = memory_manager.c
MEMORY_MANAGER_OBJ = memory_manager.o
MEMORY_MANAGER_LIB = libmemory_manager.so
LINKED_LIST_SRC = linked_list.c
LINKED_LIST_APP = linked_list_app

# Targets

# Compile memory manager as a dynamic library
mmanager: $(MEMORY_MANAGER_SRC)
	$(CC) $(CFLAGS) -c $(MEMORY_MANAGER_SRC) -o $(MEMORY_MANAGER_OBJ)
	$(CC) $(LDFLAGS) -o $(MEMORY_MANAGER_LIB) $(MEMORY_MANAGER_OBJ)

# Compile linked list application and link with the memory manager library
list: mmanager $(LINKED_LIST_SRC)
	$(CC) $(CFLAGS) $(LINKED_LIST_SRC) -o $(LINKED_LIST_APP) -I. $(LINK_FLAGS)

# Build both memory manager library and linked list application
all: mmanager list

# Clean up generated files
clean:
	rm -f $(MEMORY_MANAGER_OBJ) $(MEMORY_MANAGER_LIB) $(LINKED_LIST_APP)

.PHONY: all mmanager list clean
