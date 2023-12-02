#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Deque {
    int items[MAX_SIZE];
    int front, rear;
};

void initDeque(struct Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isDequeEmpty(struct Deque* deque) {
    return (deque->front == -1 && deque->rear == -1);
}

int isDequeFull(struct Deque* deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

void insertFront(struct Deque* deque, int value) {
    if (isDequeFull(deque)) {
        printf("Deque is full. Cannot insert at the front.\n");
    } else {
        if (isDequeEmpty(deque)) {
            deque->front = deque->rear = 0;
        } else {
            deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
        }
        deque->items[deque->front] = value;
        printf("Inserted %d at the front.\n", value);
    }
}

void insertRear(struct Deque* deque, int value) {
    if (isDequeFull(deque)) {
        printf("Deque is full. Cannot insert at the rear.\n");
    } else {
        if (isDequeEmpty(deque)) {
            deque->front = deque->rear = 0;
        } else {
            deque->rear = (deque->rear + 1) % MAX_SIZE;
        }
        deque->items[deque->rear] = value;
        printf("Inserted %d at the rear.\n", value);
    }
}

int removeFront(struct Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty. Cannot remove from the front.\n");
        return -1; // indicating failure
    } else {
        int removedValue = deque->items[deque->front];
        if (deque->front == deque->rear) {
            initDeque(deque);
        } else {
            deque->front = (deque->front + 1) % MAX_SIZE;
        }
        printf("Removed %d from the front.\n", removedValue);
        return removedValue;
    }
}

int removeRear(struct Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty. Cannot remove from the rear.\n");
        return -1; // indicating failure
    } else {
        int removedValue = deque->items[deque->rear];
        if (deque->front == deque->rear) {
            initDeque(deque);
        } else {
            deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
        }
        printf("Removed %d from the rear.\n", removedValue);
        return removedValue;
    }
}

void displayDeque(struct Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque: ");
        int i = deque->front;
        do {
            printf("%d ", deque->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (deque->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    struct Deque deque;
    initDeque(&deque);

    insertFront(&deque, 10);
    insertRear(&deque, 20);
    insertFront(&deque, 5);

    displayDeque(&deque);

    removeFront(&deque);
    removeRear(&deque);

    displayDeque(&deque);

    return 0;
}
