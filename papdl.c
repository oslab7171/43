#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Stack {
    struct Node* top;
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

// Function to initialize an empty stack
struct Stack* initializeStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack != NULL) {
        stack->top = NULL;
    }
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    if (newNode != NULL) {
        if (isEmpty(stack)) {
            stack->top = newNode;
        } else {
            newNode->prev = NULL;
            newNode->next = stack->top;
            stack->top->prev = newNode;
            stack->top = newNode;
        }
        printf("%d pushed onto the stack.\n", data);
    } else {
        printf("Memory allocation failed. Cannot push.\n");
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Indicates stack underflow
    }

    int poppedValue = stack->top->data;
    struct Node* temp = stack->top;
    
    if (stack->top->next != NULL) {
        stack->top = stack->top->next;
        stack->top->prev = NULL;
    } else {
        stack->top = NULL;
    }

    free(temp);
    printf("%d popped from the stack.\n", poppedValue);
    return poppedValue;
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory occupied by the stack
void freeStack(struct Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

int main() {
    struct Stack* stack = initializeStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    display(stack); // Output: Stack: 30 20 10

    pop(stack);
    display(stack); // Output: Stack: 20 10

    pop(stack);
    pop(stack);
    pop(stack); // Output: Stack is empty. Cannot pop.

    freeStack(stack);

    return 0;
}
