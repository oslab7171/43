#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for the stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to initialize a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0';
}

// Function to return the top element of the stack
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char* infix, char* prefix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j;
    i = j = 0;

    // Reverse the infix expression
    reverseString(infix);

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i++];
        } else if (infix[i] == ')') {
            push(stack, infix[i++]);
        } else if (infix[i] == '(') {
            while (!isEmpty(stack) && peek(stack) != ')') {
                prefix[j++] = pop(stack);
            }
            pop(stack); // Pop ')' from the stack
            i++;
        } else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && getPrecedence(infix[i]) < getPrecedence(peek(stack))) {
                prefix[j++] = pop(stack);
            }
            push(stack, infix[i++]);
        } else {
            // Invalid character in the expression
            printf("Invalid expression\n");
            exit(1);
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(stack)) {
        prefix[j++] = pop(stack);
    }

    prefix[j] = '\0';

    // Reverse the final prefix expression to get the correct order
    reverseString(prefix);
}

// Function to evaluate a prefix expression
int evaluatePrefix(char* prefix) {
    struct Stack* stack = createStack(strlen(prefix));
    int i, operand1, operand2;

    for (i = 0; prefix[i] != '\0'; i++) {
        if (isdigit(prefix[i])) {
            push(stack, prefix[i] - '0');
        } else {
            operand1 = pop(stack);
            operand2 = pop(stack);
            switch (prefix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(stack);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result after evaluation: %d\n", result);

    return 0;
}
