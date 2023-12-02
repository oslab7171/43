#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode != NULL) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }
    return head;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode != NULL) {
        if (head == NULL) {
            return newNode;
        }

        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
        return head;
    }
    return head;
}

// Function to insert a node after a specific node in the doubly linked list
struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Cannot insert after a NULL node.\n");
        return head;
    }

    struct Node* newNode = createNode(data);
    if (newNode != NULL) {
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode->next != NULL) {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        return head;
    }
    return head;
}

// Function to delete a node with a specific value from the doubly linked list
struct Node* deleteNode(struct Node* head, int data) {
    struct Node* current = head;

    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found.\n", data);
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        // Deleting the first node
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Node with data %d deleted.\n", data);
    return head;
}

// Function to display the doubly linked list in forward direction
void displayForward(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to display the doubly linked list in reverse direction
void displayReverse(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }

    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Function to free the memory occupied by the doubly linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    // Display the list in forward and reverse direction
    printf("Doubly Linked List (Forward): ");
    displayForward(head);
    printf("Doubly Linked List (Reverse): ");
    displayReverse(head);

    // Insert nodes at the end
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    // Display the list in forward and reverse direction
    printf("Doubly Linked List (Forward): ");
    displayForward(head);
    printf("Doubly Linked List (Reverse): ");
    displayReverse(head);

    // Insert a node after a specific node
    struct Node* node2 = head->next;
    head = insertAfterNode(head, node2, 100);

    // Display the list in forward and reverse direction
    printf("Doubly Linked List (Forward): ");
    displayForward(head);
    printf("Doubly Linked List (Reverse): ");
    displayReverse(head);

    // Delete a node with a specific value
    head = deleteNode(head, 4);

    // Display the list in forward and reverse direction
    printf("Doubly Linked List (Forward): ");
    displayForward(head);
    printf("Doubly Linked List (Reverse): ");
    displayReverse(head);

    // Free
}