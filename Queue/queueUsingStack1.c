//with structure

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

typedef struct Queue {
    Stack stack1;
    Stack stack2;
} Queue;

void initQueue(Queue* queue) {
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

void enqueue(Queue* queue, int data) {
    push(&queue->stack1, data);
    printf("Enqueued: %d\n", data);
}

int dequeue(Queue* queue) {
    if (isEmpty(&queue->stack1) && isEmpty(&queue->stack2)) {
        printf("Queue is empty!\n");
        return -1;
    }

    // If stack2 is empty, transfer all elements from stack1 to stack2
    if (isEmpty(&queue->stack2)) {
        while (!isEmpty(&queue->stack1)) {
            int temp = pop(&queue->stack1);
            push(&queue->stack2, temp);
        }
    }
    // Pop the top element from stack2
    return pop(&queue->stack2);
}

int main() {
    Queue queue;
    initQueue(&queue);

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
                enqueue(&queue, value);
                break;
            case 2:
                value = dequeue(&queue);
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
