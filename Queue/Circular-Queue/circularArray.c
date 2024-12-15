#include <stdio.h>
#include <stdlib.h>

#define N 5

int queue[N];
int front = -1, rear = -1;

int isFull() {
    return ((rear + 1) % N == front);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty()) { // First element
        front = rear = 0;
    } else {
        rear = (rear + 1) % N;
    }
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Underflow condition\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear) { // Queue has only one element
        front = rear = -1;
    } else {
        front = (front + 1) % N;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot peek\n");
        return -1;
    }
    return queue[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.isEmpty\n5.isFull\n6.Display Queue\n7.Exit");
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
                if (isFull()) {
                    printf("\nQueue is Full\n");
                } else {
                    printf("\nQueue is NOT Full\n");
                }
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);

            default:
                printf("\nWrong choice!!!\n");
        }
    }
    return 0;
}
