#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->items[++stack->top] = value;
    }
}

int pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    } else {
        return -1; // Stack is empty
    }
}

int is_empty(struct Stack* stack) {
    return stack->top == -1;
}

int factorial(int n) {
    struct Stack stack;
    initStack(&stack);
    push(&stack, n);

    int result = 1;

    while (!is_empty(&stack)) {
        int current = pop(&stack);
        result *= current;

        if (current > 1) {
            push(&stack, current - 1);
        }
    }

    return result;
}

int main() {
    int number;

    printf("Enter a number to find its factorial: ");
    scanf("%d", &number);

    printf("Factorial of %d is: %d\n", number, factorial(number));

    return 0;
}
