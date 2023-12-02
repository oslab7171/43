#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoublyLinkedList {
    struct Node* head;
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

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct DoublyLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to display the doubly linked list
void display(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted doubly linked lists
struct DoublyLinkedList mergeSortedLists(struct DoublyLinkedList list1, struct DoublyLinkedList list2) {
    struct DoublyLinkedList mergedList;
    mergedList.head = NULL;

    struct Node* current1 = list1.head;
    struct Node* current2 = list2.head;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data < current2->data) {
            insertEnd(&mergedList, current1->data);
            current1 = current1->next;
        } else {
            insertEnd(&mergedList, current2->data);
            current2 = current2->next;
        }
    }

    // If any list has remaining elements
    while (current1 != NULL) {
        insertEnd(&mergedList, current1->data);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insertEnd(&mergedList, current2->data);
        current2 = current2->next;
    }

    return mergedList;
}

int main() {
    struct DoublyLinkedList list1, list2, mergedList;
    list1.head = NULL;
    list2.head = NULL;
    mergedList.head = NULL;

    // Insert elements into the first sorted doubly linked list
    insertEnd(&list1, 2);
    insertEnd(&list1, 5);
    insertEnd(&list1, 8);

    // Insert elements into the second sorted doubly linked list
    insertEnd(&list2, 3);
    insertEnd(&list2, 6);
    insertEnd(&list2, 9);

    printf("Doubly Linked List 1: ");
    display(&list1);

    printf("Doubly Linked List 2: ");
    display(&list2);

    mergedList = mergeSortedLists(list1, list2);

    printf("Merged Doubly Linked List: ");
    display(&mergedList);

    return 0;
}
