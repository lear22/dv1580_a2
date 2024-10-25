# Compiles the memory manager as a dynamic library
mmanager:
	gcc -Wall -fPIC -c memory_manager.c
	gcc -shared -o libmemory_manager.so memory_manager.o

# Compiles the linked list application and links it with libmemory_manager.so
list: mmanager
	gcc -Wall -fPIC -c linked_list.c
	gcc -Wall -fPIC -c main.c
	gcc main.o linked_list.o -o linked_list_app -I. -L. -lmemory_manager

# Compiles the test_linked_list as a separate executable
test_linked_list: mmanager
	gcc -Wall -fPIC test_linked_list.c linked_list.o -o test_linked_list -I. -L. -lmemory_manager -lpthread -lm

# Default build: builds both the memory manager and linked list application
all: mmanager list test_linked_list

# Cleans the directory
clean:
	rm -f *.o *.so linked_list_app test_linked_list
