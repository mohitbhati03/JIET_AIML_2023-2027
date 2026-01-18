#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev; // Previous pointer for doubly linked list
};

struct node *head = NULL;

void beginsert();
void begin_delete();
void display();
void traverse();
void initializeList();
struct node* getLastNode();

int main() {
    int choice = 0;


    while (choice != 5) {
        printf("\n...Choose One Option from the following List...\n");
        printf("1. Insert in beginning\n2. Delete from Beginning\n3. Traverse\n4. Display\n5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                beginsert();
                break;
            case 2:
                begin_delete();
                break;
            case 3:
                traverse();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice.\n");
        }
    }
    return 0;
}

struct node* getLastNode() {
    return head ? head->prev : NULL;
}

void beginsert() {
    struct node *ptr, *lastNode;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOverflow\n");
    } else {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL) {
            ptr->next = ptr->prev = ptr;
            head = ptr;
        } else {
            lastNode = getLastNode();
            ptr->next = head;
            ptr->prev = lastNode;
            lastNode->next = ptr;
            head->prev = ptr;
            head = ptr;
        }
        printf("Item inserted.\n");
    }
}

void begin_delete() {
    struct node *ptr, *lastNode;
    if (head == NULL) {
        printf("\nList is empty.\n");
    } else if (head->next == head) {
        // Single node case
        free(head);
        head = NULL;
        printf("Item deleted from the beginning.\n");
    } else {
        lastNode = getLastNode();
        ptr = head;
        head = head->next;
        head->prev = lastNode;
        lastNode->next = head;
        free(ptr);
        printf("Item deleted from the beginning.\n");
    }
}

void traverse() {
    struct node *ptr;
    int item, i = 1;
    int found = 0;
    if (head == NULL) {
        printf("\nEmpty List\n");
        return;
    }
    
    printf("\nEnter searching item: ");
    scanf("%d", &item);

    ptr = head;
    do {
        if (ptr->data == item) {
            printf("Item found at location %d\n", i);
            found = 1;
            break;
        }
        i++;
        ptr = ptr->next;
    } while (ptr != head);

    if (!found) {
        printf("Item not found\n");
    }
}

void display() {
    struct node *ptr;
    if (head == NULL) {
        printf("Nothing to print\n");
        return;
    }

    printf("\nPrinting values:\n");
    ptr = head;
    do {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}