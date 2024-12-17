//Used 1 queue for implementation

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue (Stack) is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = value;
}

// Dequeue operation
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue (Stack) is empty!\n");
        return -1;
    }
    return queue[front++];
}

// Push operation
void push(int value) { //O(n) for push
    enqueue(value);

    // Rotate the elements to maintain stack order
    for (int i = 0; i < rear - front; i++) {
        enqueue(dequeue());
    }
    printf("Pushed %d onto the stack.\n", value);
}

// Pop operation
int pop() { //O(1) for pop
    if (front == -1 || front > rear) {
        printf("Stack is empty!\n");
        return -1;
    }
    return dequeue();
}

// Peek (Top) operation
int top() {
    if (front == -1 || front > rear) {
        printf("Stack is empty!\n");
        return -1;
    }
    return queue[front];
}

// Check if stack is empty
int isStackEmpty() {
    return front == -1 || front > rear;
}

// Main function for stack menu
int main() {
    int choice, value;
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top Element)\n");
        printf("4. Check if Empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = top();
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                if (isStackEmpty()) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty.\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
