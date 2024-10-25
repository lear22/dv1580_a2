#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "memory_manager.h"

// Initializes the linked list
void list_init(Node** head, size_t size) 
{
    if (head == NULL) 
    {
        fprintf(stderr, "Error: head pointer is NULL.\n");
        return;
    }
    *head = NULL;  // Initialize the head to NULL
}

// Inserts a new node with specified data at the end
void list_insert(Node** head, uint16_t data) 
{
    if (head == NULL) 
    {
        fprintf(stderr, "Error: head pointer is NULL.\n");
        return;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));  // Allocate memory for the new node
    if (new_node == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return;
    }
    new_node->data = data; 
    new_node->next = NULL; 

    if (*head == NULL) 
    {
        *head = new_node;  // The list was empty, set the new node as the head
    } 
    else 
    {
        Node* last = *head;
        while (last->next != NULL) 
        {
            last = last->next;  // Traverse to the end of the list
        }
        last->next = new_node;  // Link the new node at the end
    }
}

// Inserts a new node immediately after the given node
void list_insert_after(Node* prev_node, uint16_t data) 
{
    if (prev_node == NULL) 
    {
        fprintf(stderr, "Error: The given previous node cannot be NULL.\n");
        return;
    }
    
    Node* new_node = (Node*)mem_alloc(sizeof(Node));
    if (new_node == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return;
    }
    new_node->data = data; 
    new_node->next = prev_node->next; 
    prev_node->next = new_node;  // Link the new node after the previous node
}

// Inserts a new node immediately before the given node
void list_insert_before(Node** head, Node* next_node, uint16_t data) 
{
    if (head == NULL || *head == NULL) 
    {
        fprintf(stderr, "Error: The list is empty or head pointer is NULL.\n");
        return;
    }
    
    if (next_node == *head)  // Inserting before the head
    { 
        Node* new_node = (Node*)mem_alloc(sizeof(Node));
        if (new_node == NULL) 
        {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            return;
        }
        new_node->data = data; 
        new_node->next = *head; 
        *head = new_node; // Update head to new node
        return;
    }
    
    Node* current = *head;
    while (current != NULL && current->next != next_node) 
    {
        current = current->next; // Find the node before next_node
    }

    if (current == NULL) 
    {
        fprintf(stderr, "Error: The next node is not found in the list.\n");
        return;
    }
    
    Node* new_node = (Node*)mem_alloc(sizeof(Node));
    if (new_node == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return;
    }
    new_node->data = data; 
    new_node->next = next_node; 
    current->next = new_node; // Link the new node
}

// Deletes a node with the specified data
void list_delete(Node** head, uint16_t data) 
{
    if (head == NULL || *head == NULL) 
    {
        fprintf(stderr, "Error: The list is empty or head pointer is NULL.\n");
        return;
    }
    
    Node* temp = *head;
    Node* prev = NULL;

    // Check if the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == data) 
    {
        *head = temp->next; // Change head
        mem_free(temp); // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != data) 
    {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the list
    if (temp == NULL) 
    {
        fprintf(stderr, "Error: Node with data %d not found.\n", data);
        return;
    }

    prev->next = temp->next; // Unlink the node
    mem_free(temp); // Free memory
}

// Searches for a node with the specified data
Node* list_search(Node** head, uint16_t data) 
{
    if (head == NULL || *head == NULL) 
    {
        fprintf(stderr, "Error: The list is empty or head pointer is NULL.\n");
        return NULL;
    }

    Node* current = *head;
    while (current != NULL) 
    {
        if (current->data == data) 
        {
            return current; // Return the node if found
        }
        current = current->next;
    }
    return NULL; // Return NULL if not found
}

// Displays all elements in the linked list
void list_display(Node** head) 
{
    if (head == NULL || *head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    Node* current = *head;
    printf("[");
    while (current != NULL) 
    {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) 
        {
            printf(", ");
        }
    }
    printf("]\n");
}

// Displays elements between two nodes
void list_display_range(Node** head, Node* start_node, Node* end_node) 
{
    if (head == NULL || *head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    Node* current = start_node ? start_node : *head;
    printf("[");
    while (current != NULL && current != end_node) 
    {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL && current != end_node) 
        {
            printf(", ");
        }
    }
    printf("]\n");
}

// Returns the count of nodes in the list
int list_count_nodes(Node** head) 
{
    if (head == NULL || *head == NULL) 
    {
        return 0; // The list is empty
    }

    int count = 0;
    Node* current = *head;
    while (current != NULL) 
    {
        count++;
        current = current->next;
    }
    return count;
}

// Frees all nodes in the linked list
void list_cleanup(Node** head) 
{
    if (head == NULL || *head == NULL) 
    {
        return; // The list is empty
    }

    Node* current = *head;
    Node* next_node;
    while (current != NULL) 
    {
        next_node = current->next;
        mem_free(current); // Free the current node
        current = next_node;
    }
    *head = NULL; // Set head to NULL after cleanup
}
