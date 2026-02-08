#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* newNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}

void insertAfter(struct Node* prevNode, int data) {
    if (!prevNode) return;
    struct Node* n = newNode(data);
    n->next = prevNode->next;
    n->prev = prevNode;
    if (prevNode->next) prevNode->next->prev = n;
    prevNode->next = n;
}

void deleteNode(struct Node** head, struct Node* del) {
    if (!head || !del) return;
    if (*head == del) *head = del->next;
    if (del->next) del->next->prev = del->prev;
    if (del->prev) del->prev->next = del->next;
    free(del);
}

void display(struct Node* head) {
    while (head) {
        printf("%d %s", head->data, head->next ? "<-> " : "\n");
        head = head->next;
    }
}

int main() {
    struct Node* head = newNode(10);
    insertAfter(head, 20);
    insertAfter(head->next, 30);
    
    printf("Initial List: ");
    display(head);

    printf("Inserting 25 after 20...\n");
    insertAfter(head->next, 25);
    display(head);

    printf("Deleting 20...\n");
    deleteNode(&head, head->next);
    display(head);

    return 0;
}