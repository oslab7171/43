#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
struct Node* insertFront(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to display the elements of a linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to reverse a linked list iteratively
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // 'prev' is now the new head of the reversed list
    return prev;
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    head = insertFront(head, 1);
    head = insertFront(head, 2);
    head = insertFront(head, 3);
    head = insertFront(head, 4);
    head = insertFront(head, 5);

    // Display the original list
    printf("Original List: ");
    displayList(head);

    // Reverse the list
    head = reverseList(head);

    // Display the reversed list
    printf("Reversed List: ");
    displayList(head);

    return 0;
}
