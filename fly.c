#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CUSTOMERS 20

struct Customer {
    int id;
    int arrival_time;
};

struct Queue {
    struct Customer* customers[MAX_CUSTOMERS];
    int front, rear;
};

struct Queue regular_queue, frequent_queue;

void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, struct Customer* customer) {
    if (queue->rear == MAX_CUSTOMERS - 1) {
        printf("Queue is full. Customer %d cannot be enqueued.\n", customer->id);
    } else {
        if (isQueueEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear++;
        queue->customers[queue->rear] = customer;
    }
}

struct Customer* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    } else {
        struct Customer* customer = queue->customers[queue->front];

        if (queue->front == queue->rear) {
            initQueue(queue);
        } else {
            queue->front++;
        }

        return customer;
    }
}

void serveCustomers(struct Queue* queue, const char* customerType) {
    int total_waiting_time = 0;
    int total_customers_served = 0;

    while (!isQueueEmpty(queue)) {
        struct Customer* current_customer = dequeue(queue);

        // Simulate serving the customer
        printf("Serving %s customer %d\n", customerType, current_customer->id);

        // Calculate waiting time
        int waiting_time = time(NULL) - current_customer->arrival_time;
        total_waiting_time += waiting_time;
        total_customers_served++;

        free(current_customer);
    }

    if (total_customers_served > 0) {
        double average_waiting_time = (double)total_waiting_time / total_customers_served;
        printf("Average waiting time for %s customers: %.2f seconds\n", customerType, average_waiting_time);
    } else {
        printf("No %s customers served.\n", customerType);
    }
}

void simulateAirlines() {
    srand(time(NULL));

    initQueue(&regular_queue);
    initQueue(&frequent_queue);

    // Simulate customers arriving at the airport
    for (int i = 1; i <= MAX_CUSTOMERS; i++) {
        struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
        new_customer->id = i;
        new_customer->arrival_time = time(NULL);

        // Randomly assign customers to regular or frequent queue
        if (rand() % 2 == 0) {
            enqueue(&regular_queue, new_customer);
        } else {
            enqueue(&frequent_queue, new_customer);
        }
    }

    // Serve customers using different strategies
    printf("\nServing Customers:\n");
    serveCustomers(&regular_queue, "Regular");
    serveCustomers(&frequent_queue, "Frequent Flyer");
}

int main() {
    simulateAirlines();

    return 0;
}
