CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -L. -lmemory_manager

# Target to build the memory manager as a dynamic library
mmanager: memory_manager.o
	$(CC) -shared -o libmemory_manager.so memory_manager.o

# Target to build the linked list application
list: linked_list.o
	$(CC) $(CFLAGS) linked_list.c -o linked_list_app -I. $(LDFLAGS)

# Build all: memory manager and linked list application
all: mmanager list

# Object files for memory_manager
memory_manager.o: memory_manager.c memory_manager.h
	$(CC) $(CFLAGS) -c memory_manager.c

# Object files for linked_list
linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

# Clean up generated files
clean:
	rm -f *.o *.so linked_list_app
