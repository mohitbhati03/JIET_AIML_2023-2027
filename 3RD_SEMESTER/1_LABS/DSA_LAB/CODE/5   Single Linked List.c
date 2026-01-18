#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void delete(Node** head, int data) {
    Node* current = *head;
    Node* previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter element to insert: ");
                int data;
                scanf("%d", &data);
                insert(&head, data);
                break;
            }
            case 2: {
                printf("Enter element to delete: ");
                int data;
                scanf("%d", &data);
                delete(&head, data);
                break;
            }
            case 3: {
                printList(head);
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