CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -L. -lmemory_manager

# Target to build the memory manager as a dynamic library
mmanager: memory_manager.o
	$(CC) -shared -o libmemory_manager.so memory_manager.o

# Target to build the linked list application with main.c
list: main.o linked_list.o
	$(CC) main.o linked_list.o -o linked_list_app -I. $(LDFLAGS)

# Default target builds both the library and application
all: mmanager list

# Object files for memory_manager
memory_manager.o: memory_manager.c memory_manager.h
	$(CC) $(CFLAGS) -c memory_manager.c

# Object files for linked_list
linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

# Object file for main (with main function)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Clean up generated files
clean:
	rm -f *.o *.so linked_list_app
