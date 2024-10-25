#include "linked_list.h"
#include <stdio.h>

int main() {
    Node *head = NULL;
    list_init(&head, 10);

    list_insert(&head, 20);
    list_insert(&head, 30);
    list_insert(&head, 40);

    list_display(&head);

    list_cleanup(&head);
    return 0;
}
