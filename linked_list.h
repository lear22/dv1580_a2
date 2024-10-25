#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>
#include "memory_manager.h"

// Node structure definition
typedef struct Node 
{
    uint16_t data;  // Stores the data as an unsigned 16-bit integer
    struct Node* next;  // A pointer to the next node in the List
} Node;

// Function prototypes
void list_init(Node** head, size_t size);  // Initializes the linked list
void list_insert(Node** head, uint16_t data);  // Inserts a new node with the specified data at the end
void list_insert_after(Node* prev_node, uint16_t data);  // Inserts a new node after a given node
void list_insert_before(Node** head, Node* next_node, uint16_t data);  // Inserts a new node before a given node
void list_delete(Node** head, uint16_t data);  // Deletes a node with the specified data
Node* list_search(Node** head, uint16_t data);  // Searches for a node with the specified data
void list_display(Node** head);  // Displays all elements in the linked list
void list_display_range(Node** head, Node* start_node, Node* end_node);  // Displays elements between two nodes
int list_count_nodes(Node** head);  // Returns the count of nodes in the list
void list_cleanup(Node** head);  // Frees all nodes in the linked list

#endif // LINKED_LIST_H
