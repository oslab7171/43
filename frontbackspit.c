#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
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

// Function to split a linked list into front and back halves
void FrontBackSplit(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    if (source == NULL || source->next == NULL) {
        // Handle cases where the length of the list is less than 2
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    struct Node* slow = source;
    struct Node* fast = source->next;

    // Move 'fast' two steps and 'slow' one step
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is at the midpoint, split the list into front and back halves
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    head = insertEnd(head, 2);
    // head = insertEnd(head, 3);
    // head = insertEnd(head, 5);
    // head = insertEnd(head, 7);
    // head = insertEnd(head, 11);

    // Display the original list
    printf("Original List: ");
    displayList(head);

    // Split the list into front and back halves
    struct Node* frontHalf = NULL;
    struct Node* backHalf = NULL;
    FrontBackSplit(head, &frontHalf, &backHalf);

    // Display the front and back halves
    printf("Front Half: ");
    displayList(frontHalf);

    printf("Back Half: ");
    displayList(backHalf);

    return 0;
}
