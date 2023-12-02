#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent multiple stacks
struct MultipleStack {
    int top1, top2, top3;
    int array[MAX_SIZE];
};

// Function to initialize multiple stacks
void initializeStacks(struct MultipleStack* stacks) {
    stacks->top1 = -1;
    stacks->top2 = MAX_SIZE / 2 - 1;
    stacks->top3 = MAX_SIZE;
}

// Function to check if stack 1 is full
int isStack1Full(struct MultipleStack* stacks) {
    return stacks->top1 == (MAX_SIZE / 2 - 1);
}

// Function to check if stack 2 is full
int isStack2Full(struct MultipleStack* stacks) {
    return stacks->top2 == (MAX_SIZE - 1);
}

// Function to check if stack 3 is full
int isStack3Full(struct MultipleStack* stacks) {
    return stacks->top3 == (MAX_SIZE / 2);
}

// Function to check if stack 1 is empty
int isStack1Empty(struct MultipleStack* stacks) {
    return stacks->top1 == -1;
}

// Function to check if stack 2 is empty
int isStack2Empty(struct MultipleStack* stacks) {
    return stacks->top2 == (MAX_SIZE / 2 - 1);
}

// Function to check if stack 3 is empty
int isStack3Empty(struct MultipleStack* stacks) {
    return stacks->top3 == MAX_SIZE;
}

// Function to push an element onto stack 1
void pushStack1(struct MultipleStack* stacks, int item) {
    if (isStack1Full(stacks)) {
        printf("Stack 1 Overflow\n");
        return;
    }
    stacks->array[++stacks->top1] = item;
}

// Function to push an element onto stack 2
void pushStack2(struct MultipleStack* stacks, int item) {
    if (isStack2Full(stacks)) {
        printf("Stack 2 Overflow\n");
        return;
    }
    stacks->array[++stacks->top2] = item;
}

// Function to push an element onto stack 3
void pushStack3(struct MultipleStack* stacks, int item) {
    if (isStack3Full(stacks)) {
        printf("Stack 3 Overflow\n");
        return;
    }
    stacks->array[--stacks->top3] = item;
}

// Function to pop an element from stack 1
int popStack1(struct MultipleStack* stacks) {
    if (isStack1Empty(stacks)) {
        printf("Stack 1 Underflow\n");
        return -1; // Return an error value
    }
    return stacks->array[stacks->top1--];
}

// Function to pop an element from stack 2
int popStack2(struct MultipleStack* stacks) {
    if (isStack2Empty(stacks)) {
        printf("Stack 2 Underflow\n");
        return -1; // Return an error value
    }
    return stacks->array[stacks->top2--];
}

// Function to pop an element from stack 3
int popStack3(struct MultipleStack* stacks) {
    if (isStack3Empty(stacks)) {
        printf("Stack 3 Underflow\n");
        return -1; // Return an error value
    }
    return stacks->array[stacks->top3++];
}

// Function to display stack 1
void displayStack1(struct MultipleStack* stacks) {
    printf("Stack 1: ");
    for (int i = 0; i <= stacks->top1; i++) {
        printf("%d ", stacks->array[i]);
    }
    printf("\n");
}

// Function to display stack 2
void displayStack2(struct MultipleStack* stacks) {
    printf("Stack 2: ");
    for (int i = MAX_SIZE / 2; i <= stacks->top2; i++) {
        printf("%d ", stacks->array[i]);
    }
    printf("\n");
}

// Function to display stack 3
void displayStack3(struct MultipleStack* stacks) {
    printf("Stack 3: ");
    for (int i = MAX_SIZE - 1; i >= stacks->top3; i--) {
        printf("%d ", stacks->array[i]);
    }
    printf("\n");
}

int main() {
    struct MultipleStack stacks;
    initializeStacks(&stacks);

    pushStack1(&stacks, 1);
    pushStack1(&stacks, 2);
    pushStack2(&stacks, 3);
    pushStack2(&stacks, 4);
    pushStack3(&stacks, 5);
    pushStack3(&stacks, 6);

    displayStack1(&stacks);
    displayStack2(&stacks);
    displayStack3(&stacks);

    printf("Pop from Stack 1: %d\n", popStack1(&stacks));
    printf("Pop from Stack 2: %d\n", popStack2(&stacks));
    printf("Pop from Stack 3: %d\n", popStack3(&stacks));

    displayStack1(&stacks);
    displayStack2(&stacks);
    displayStack3(&stacks);

    return 0;
}
