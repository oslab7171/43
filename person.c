#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 5

struct Stack {
    int items[MAX_ROOMS];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, int room) {
    if (stack->top < MAX_ROOMS - 1) {
        stack->items[++stack->top] = room;
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

void unlock_treasure(int decimal_code) {
    struct Stack stack;
    initStack(&stack);

    // Move from room 1 to 5
    for (int room = 1; room <= MAX_ROOMS; room++) {
        push(&stack, room);
    }

    // Move from room 5 to 1 and convert decimal code to binary
    while (!is_empty(&stack)) {
        int current_room = pop(&stack);
        int binary_digit = (decimal_code >> (MAX_ROOMS - current_room)) & 1;
        printf("In Room %d: Binary Digit - %d\n", current_room, binary_digit);
    }

    printf("Treasure Unlocked with Decimal Code: %d\n", decimal_code);
}

int main() {
    int decimal_code;

    printf("Enter the decimal code from the last room: ");
    scanf("%d", &decimal_code);

    unlock_treasure(decimal_code);

    return 0;
}







// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// // Structure for the stack
// struct Stack {
//     int top;
//     unsigned capacity;
//     int* array;
// };

// // Function to initialize a stack
// struct Stack* createStack(unsigned capacity) {
//     struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
//     stack->top = -1;
//     stack->capacity = capacity;
//     stack->array = (int*)malloc(stack->capacity * sizeof(int));
//     return stack;
// }

// // Function to check if the stack is empty
// int isEmpty(struct Stack* stack) {
//     return stack->top == -1;
// }

// // Function to push an element onto the stack
// void push(struct Stack* stack, int item) {
//     stack->array[++stack->top] = item;
// }

// // Function to pop an element from the stack
// int pop(struct Stack* stack) {
//     if (!isEmpty(stack))
//         return stack->array[stack->top--];
//     return -1; // Return an error value
// }

// // Function to convert decimal to binary and push binary digits onto the stack
// void decimalToBinary(struct Stack* forwardStack, int decimalNumber) {
//     while (decimalNumber > 0) {
//         int remainder = decimalNumber % 2;
//         push(forwardStack, remainder);
//         decimalNumber /= 2;
//     }
// }

// // Function to move forward from room 1 to room 5
// void moveForward(struct Stack* forwardStack) {
//     printf("Moving forward: ");
//     while (!isEmpty(forwardStack)) {
//         printf("%d ", pop(forwardStack));
//     }
//     printf("\n");
// }

// // Function to move backward from room 5 to room 1
// void moveBackward(struct Stack* backwardStack) {
//     printf("Moving backward: ");
//     while (!isEmpty(backwardStack)) {
//         printf("%d ", pop(backwardStack));
//     }
//     printf("\n");
// }

// int main() {
//     struct Stack* forwardStack = createStack(MAX_SIZE);
//     struct Stack* backwardStack = createStack(MAX_SIZE);

//     int decimalNumber;

//     // Assume the decimal number in the last room
//     printf("Enter the decimal number in the last room: ");
//     scanf("%d", &decimalNumber);

//     // Convert decimal to binary and push binary digits onto the forward stack
//     decimalToBinary(forwardStack, decimalNumber);

//     // Move forward from room 1 to room 5
//     moveForward(forwardStack);

//     // Move backward from room 5 to room 1
//     moveBackward(forwardStack);

//     free(forwardStack->array);
//     free(forwardStack);

//     free(backwardStack->array);
//     free(backwardStack);

//     return 0;
// }
