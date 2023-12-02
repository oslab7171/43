#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
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

// Function to initialize an empty queue
struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue != NULL) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to add an element to the rear of the queue (enqueue)
void add(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (newNode != NULL) {
        if (isEmpty(queue)) {
            queue->front = newNode;
            queue->rear = newNode;
        } else {
            newNode->prev = queue->rear;
            queue->rear->next = newNode;
            queue->rear = newNode;
        }
        printf("%d added to the queue.\n", data);
    } else {
        printf("Memory allocation failed. Cannot add to the queue.\n");
    }
}

// Function to delete an element from the front of the queue (dequeue)
int delete(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot delete.\n");
        return -1; // Indicates queue underflow
    }

    int deletedValue = queue->front->data;
    struct Node* temp = queue->front;

    if (queue->front->next != NULL) {
        queue->front = queue->front->next;
        queue->front->prev = NULL;
    } else {
        queue->front = NULL;
        queue->rear = NULL;
    }

    free(temp);
    printf("%d deleted from the queue.\n", deletedValue);
    return deletedValue;
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory occupied by the queue
void freeQueue(struct Queue* queue) {
    while (!isEmpty(queue)) {
        delete(queue);
    }
    free(queue);
}

int main() {
    struct Queue* queue = initializeQueue();

    add(queue, 10);
    add(queue, 20);
    add(queue, 30);

    display(queue); // Output: Queue: 10 20 30

    delete(queue);
    display(queue); // Output: Queue: 20 30

    delete(queue);
    delete(queue);
    delete(queue); // Output: Queue is empty. Cannot delete.

    freeQueue(queue);

    return 0;
}
