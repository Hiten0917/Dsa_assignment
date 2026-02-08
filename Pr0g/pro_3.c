#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void reversePrint(struct Node* head) {
    if (!head) return;
    reversePrint(head->next);
    printf("%d ", head->data);
}

int main() {
    struct Node* head = newNode(8);
    head->next = newNode(16);
    head->next->next = newNode(24);
    head->next->next->next = newNode(32);
    head->next->next->next->next = newNode(40);

    printf("Reverse traversal: ");
    if (!head) printf("List is empty.");
    else reversePrint(head);
    printf("\n");

    return 0;
}