#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "memory_manager.h"

typedef struct Node 
{
    uint16_t data;  // Stores the data as an unsigned 16-bit integer
    struct Node* next;  // A pointer to the next node in the List
} Node;

// Function prototypes
void list_init(Node** head);
void list_insert(Node** head, uint16_t data);
void list_delete(Node** head, uint16_t data);
Node* list_search(Node** head, uint16_t data);
void list_display(Node** head);
void list_cleanup(Node** head);

#endif  // LINKED_LIST_H
