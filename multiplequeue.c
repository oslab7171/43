#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct MultipleQueue {
    int items[MAX_SIZE * 2];  // Assuming each queue has a maximum size of MAX_SIZE
    int front1, rear1, front2, rear2;
};

void initMultipleQueue(struct MultipleQueue* mqueue) {
    mqueue->front1 = -1;
    mqueue->rear1 = -1;
    mqueue->front2 = MAX_SIZE;
    mqueue->rear2 = MAX_SIZE - 1;
}

int isQueue1Empty(struct MultipleQueue* mqueue) {
    return (mqueue->front1 == -1);
}

int isQueue2Empty(struct MultipleQueue* mqueue) {
    return (mqueue->front2 == MAX_SIZE);
}

int isQueue1Full(struct MultipleQueue* mqueue) {
    return ((mqueue->rear1 + 1) % MAX_SIZE == mqueue->front2);
}

int isQueue2Full(struct MultipleQueue* mqueue) {
    return ((mqueue->rear2 + 1) % MAX_SIZE == mqueue->front1);
}

void enqueue1(struct MultipleQueue* mqueue, int value) {
    if (isQueue1Full(mqueue)) {
        printf("Queue 1 is full. Cannot enqueue.\n");
    } else {
        if (isQueue1Empty(mqueue)) {
            mqueue->front1 = mqueue->rear1 = 0;
        } else {
            mqueue->rear1 = (mqueue->rear1 + 1) % MAX_SIZE;
        }
        mqueue->items[mqueue->rear1] = value;
        printf("Enqueued %d in Queue 1.\n", value);
    }
}

void enqueue2(struct MultipleQueue* mqueue, int value) {
    if (isQueue2Full(mqueue)) {
        printf("Queue 2 is full. Cannot enqueue.\n");
    } else {
        if (isQueue2Empty(mqueue)) {
            mqueue->front2 = mqueue->rear2 = MAX_SIZE - 1;
        } else {
            mqueue->rear2 = (mqueue->rear2 - 1 + MAX_SIZE) % MAX_SIZE;
        }
        mqueue->items[mqueue->rear2] = value;
        printf("Enqueued %d in Queue 2.\n", value);
    }
}

int dequeue1(struct MultipleQueue* mqueue) {
    if (isQueue1Empty(mqueue)) {
        printf("Queue 1 is empty. Cannot dequeue.\n");
        return -1; // indicating failure
    } else {
        int removedValue = mqueue->items[mqueue->front1];
        if (mqueue->front1 == mqueue->rear1) {
            mqueue->front1 = mqueue->rear1 = -1;
        } else {
            mqueue->front1 = (mqueue->front1 + 1) % MAX_SIZE;
        }
        printf("Dequeued %d from Queue 1.\n", removedValue);
        return removedValue;
    }
}

int dequeue2(struct MultipleQueue* mqueue) {
    if (isQueue2Empty(mqueue)) {
        printf("Queue 2 is empty. Cannot dequeue.\n");
        return -1; // indicating failure
    } else {
        int removedValue = mqueue->items[mqueue->front2];
        if (mqueue->front2 == mqueue->rear2) {
            mqueue->front2 = mqueue->rear2 = MAX_SIZE;
        } else {
            mqueue->front2 = (mqueue->front2 - 1 + MAX_SIZE) % MAX_SIZE;
        }
        printf("Dequeued %d from Queue 2.\n", removedValue);
        return removedValue;
    }
}

void displayMultipleQueue(struct MultipleQueue* mqueue) {
    if (isQueue1Empty(mqueue)) {
        printf("Queue 1 is empty.\n");
    } else {
        printf("Queue 1: ");
        int i = mqueue->front1;
        do {
            printf("%d ", mqueue->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (mqueue->rear1 + 1) % MAX_SIZE);
        printf("\n");
    }

    if (isQueue2Empty(mqueue)) {
        printf("Queue 2 is empty.\n");
    } else {
        printf("Queue 2: ");
        int i = mqueue->front2;
        do {
            printf("%d ", mqueue->items[i]);
            i = (i - 1 + MAX_SIZE) % MAX_SIZE;
        } while (i != (mqueue->rear2 - 1 + MAX_SIZE) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    struct MultipleQueue mqueue;
    initMultipleQueue(&mqueue);

    enqueue1(&mqueue, 10);
    enqueue2(&mqueue, 20);
    enqueue1(&mqueue, 5);

    displayMultipleQueue(&mqueue);

    dequeue1(&mqueue);
    dequeue2(&mqueue);

    displayMultipleQueue(&mqueue);

    return 0;
}
