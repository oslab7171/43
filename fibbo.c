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

void fibonacci(int n) {
    struct Stack stack;
    initStack(&stack);

    for (int i = n; i >= 0; i--) {
        push(&stack, i);
    }

    int a = 0, b = 1;

    while (!is_empty(&stack)) {
        int current = pop(&stack);
        printf("%d ", a);
        int temp = a;
        a = b;
        b += temp;
    }
}

int main() {
    int terms;

    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &terms);

    printf("Fibonacci Series: ");
    fibonacci(terms);

    return 0;
}
