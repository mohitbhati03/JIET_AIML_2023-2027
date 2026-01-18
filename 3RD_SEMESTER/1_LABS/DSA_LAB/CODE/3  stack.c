#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d.\n", element);
        return;
    }
    stack->data[++stack->top] = element;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

void printStack(Stack* stack) {
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter element to push: ");
                int element;
                scanf("%d", &element);
                push(&stack, element);
                break;
            }
            case 2: {
                int popped = pop(&stack);
                if (popped != -1) {
                    printf("Popped element: %d\n", popped);
                }
                break;
            }
            case 3: {
                printStack(&stack);
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                printf("Invalid choice. Try again.\n");
            }
        }
    }

    return 0;
}





//output:-
// 1. Push
// 2. Pop
// 3. Print Stack
// 4. Exit
// Enter your choice: 1
// Enter element to push: 5
// 1. Push
// 2. Pop
// 3. Print Stack
// 4. Exit
// Enter your choice: 1
// Enter element to push: 10
// 1. Push
// 2. Pop
// 3. Print Stack
// 4. Exit
// Enter your choice: 3
// Stack: 5 10
// 1. Push
// 2. Pop
// 3. Print Stack
// 4. Exit
// Enter your choice: 2
// Popped element: 10
// 1. Push
// 2. Pop
// 3. Print Stack
// 4. Exit
// Enter your choice: 3
// Stack: 5
// 1. Push
// 2. Pop
// 3. Print Stack
// 4. Exit
// Enter your choice: 4


