#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push(int* stack, int* top, int data) {
    if (*top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++(*top)] = data;
}

int pop(int* stack, int* top) {
    if (*top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[(*top)--];
}

void enqueue(int data) {
    push(stack1, &top1, data);
    printf("Enqueued: %d\n", data);
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return -1;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            push(stack2, &top2, pop(stack1, &top1));
        }
    }

    return pop(stack2, &top2);
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
