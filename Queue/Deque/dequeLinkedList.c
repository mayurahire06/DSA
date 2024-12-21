// Implementation of a Deque Using a Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

// Deque structure
typedef struct {
    Node *front, *rear;
} Deque;

// Function to initialize the deque
void initialize(Deque *dq) {
    dq->front = dq->rear = NULL;
}

// Check if the deque is empty
int isEmpty(Deque *dq) {
    return (dq->front == NULL);
}

// Function to insert an element at the front
void insertFront(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (isEmpty(dq)) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    printf("Inserted %d at the front.\n", value);
}

// Function to insert an element at the rear
void insertRear(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (isEmpty(dq)) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    printf("Inserted %d at the rear.\n", value);
}

// Function to delete an element from the front
void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from the front.\n");
        return;
    }

    Node *temp = dq->front;
    printf("Deleted %d from the front.\n", temp->data);

    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL; // If the deque becomes empty
    } else {
        dq->front->prev = NULL;
    }
    free(temp);
}

// Function to delete an element from the rear
void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from the rear.\n");
        return;
    }

    Node *temp = dq->rear;
    printf("Deleted %d from the rear.\n", temp->data);

    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL; // If the deque becomes empty
    } else {
        dq->rear->next = NULL;
    }
    free(temp);
}

// Function to display the deque elements
void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }

    Node *temp = dq->front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Menu driven interface
void menu() {
    printf("\nMenu:\n");
    printf("1. Insert at front\n");
    printf("2. Insert at rear\n");
    printf("3. Delete from front\n");
    printf("4. Delete from rear\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Main function to test the deque implementation
int main() {
    Deque dq;
    initialize(&dq);

    int choice, value;
    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
