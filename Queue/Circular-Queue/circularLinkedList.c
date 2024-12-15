#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;  
struct Node* rear = NULL;   

int isEmpty() {
    return (front == NULL);
}

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed. Enqueue operation aborted.\n");
        return;
    }
    newNode->data = value;
    if (isEmpty()) {
        front = rear = newNode;
        rear->next = front; // Point to itself to make it circular
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Rear points back to front
    }
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("underflow condition\n");
        return;
    }
    struct Node* temp = front;
    if (front == rear) { // Only one element in the queue
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // Rear points to the new front
    }
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot peek\n");
        return -1;
    }
    return front->data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front); // Traverse until back to the front
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.isEmpty\n5.Display Queue\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                value = peek();
                if (value != -1) {
                    printf("Peek element is: %d\n", value);
                }
                break;

            case 4:
                if (isEmpty()) {
                    printf("\nQueue is empty\n");
                } else {
                    printf("\nQueue is NOT empty\n");
                }
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("\nWrong choice!!!\n");
        }
    }
    return 0;
}
