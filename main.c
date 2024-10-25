#include <stdio.h>
#include "memory_manager.h"
#include "linked_list.h"

int main() {
    // Initialize Memory Manager
    mem_init(4096);
    
    // Initialize Linked List
    Node* head = NULL;
    list_init(&head);

    // Insert Elements
    list_insert(&head, 10);
    list_insert(&head, 20);
    list_insert(&head, 30);
    
    // Display List
    printf("Current List: ");
    list_display(&head);

    // Count Nodes
    printf("Number of nodes: %d\n", list_count_nodes(&head));

    // Search for a Node
    Node* found = list_search(&head, 20);
    if (found) {
        printf("Node with data %d found.\n", found->data);
    } else {
        printf("Node not found.\n");
    }

    // Delete a Node
    list_delete(&head, 20);
    printf("List after deleting 20: ");
    list_display(&head);

    // Cleanup
    list_cleanup(&head);
    mem_deinit();  // Free memory pool

    return 0;
}