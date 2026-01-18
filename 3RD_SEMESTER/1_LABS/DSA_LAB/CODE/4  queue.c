#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = queue->rear = 0;
}

int isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

int isFull(Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", element);
        return;
    }
    queue->data[queue->rear] = element;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int element = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    return element;
}

void printQueue(Queue* queue) {
    printf("Queue: ");
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    Queue queue;
    initQueue(&queue);

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter element to enqueue: ");
                int element;
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
            }
            case 2: {
                int dequeued = dequeue(&queue);
                if (dequeued != -1) {
                    printf("Dequeued element: %d\n", dequeued);
                }
                break;
            }
            case 3: {
                printQueue(&queue);
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




// output:-
// 1. Enqueue
// 2. Dequeue
// 3. Print Queue
// 4. Exit
// Enter your choice: 1
// Enter element to enqueue: 5
// 1. Enqueue
// 2. Dequeue
// 3. Print Queue
// 4. Exit
// Enter your choice: 1
// Enter element to enqueue: 10
// 1. Enqueue
// 2. Dequeue
// 3. Print Queue
// 4. Exit
// Enter your choice: 3
// Queue: 5 10
// 1. Enqueue
// 2. Dequeue
// 3. Print Queue
// 4. Exit
// Enter your choice: 2
// Dequeued element: 5
// 1. Enqueue
// 2. Dequeue
// 3. Print Queue
// 4. Exit
// Enter your choice: 3
// Queue: 10
// 1. Enqueue
// 2. Dequeue
// 3. Print Queue
// 4. Exit
// Enter your choice: 4

