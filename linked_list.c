#include "linked_list.h"

void list_init(Node** head) 
{
    *head = NULL;  // Initialize the head of the list
}

void list_insert(Node** head, uint16_t data) 
{
    Node* new_node = (Node*)mem_alloc(sizeof(Node));
    if (!new_node) 
    {
        fprintf(stderr, "Failed to allocate memory for new node.\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) 
    {
        *head = new_node;  // Insert at the head if the list is empty
    } 
    else 
    {
        Node* current = *head;
        while (current->next) 
        {
            current = current->next;  // Traverse to the end
        }
        current->next = new_node;  // Add the new node at the end
    }
}

void list_delete(Node** head, uint16_t data) 
{
    if (*head == NULL) 
    {
        return;  // Empty list
    }

    Node* current = *head;
    Node* previous = NULL;

    // Search for the node to delete
    while (current && current->data != data) 
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL) 
    {
        return;  // Data not found
    }

    if (previous == NULL) 
    {
        *head = current->next;  // Deleting the head
    } 
    else 
    {
        previous->next = current->next;  // Bypass the node to delete
    }

    mem_free(current);  // Free the memory for the deleted node
}

Node* list_search(Node** head, uint16_t data) 
{
    Node* current = *head;
    while (current) 
    {
        if (current->data == data) 
        {
            return current;  // Node found
        }
        current = current->next;
    }
    return NULL;  // Node not found
}

void list_display(Node** head) 
{
    Node* current = *head;
    printf("[");
    while (current) 
    {
        printf("%u", current->data);
        if (current->next) 
        {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

void list_cleanup(Node** head) 
{
    Node* current = *head;
    while (current) 
    {
        Node* next = current->next;
        mem_free(current);  // Free the current node
        current = next;  // Move to the next node
    }
    *head = NULL;  // Reset the head pointer
}
