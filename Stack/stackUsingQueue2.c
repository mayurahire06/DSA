#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Queue structure
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Stack structure using two linear queues
typedef struct {
    Queue q1;
    Queue q2;
} Stack;

// Function to initialize a queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if a queue is empty
int isQueueEmpty(Queue *q) {
   return (q->front == -1 || q->front > q->rear);
}

// Check if a queue is full
int isQueueFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Enqueue operation
void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) 
        q->front = 0;
    q->rear++;
    q->arr[q->rear] = value;
}

// Dequeue operation
int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = q->arr[q->front];
    if (q->front == q->rear) {
        // Reset the queue when it becomes empty
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Initialize the stack
void initStack(Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

// Push operation (using two queues)
void push(Stack *s, int value) {
    enqueue(&s->q2, value);

    // Move all elements from q1 to q2
    while (!isQueueEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Swap the queues
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

// Pop operation
int pop(Stack *s) {
    if (isQueueEmpty(&s->q1)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return dequeue(&s->q1);
}

// Peek operation
int top(Stack *s) {
    if (isQueueEmpty(&s->q1)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->q1.arr[s->q1.front];
}

// Check if stack is empty
int isStackEmpty(Stack *s) {
    return isQueueEmpty(&s->q1);
}

// Display the elements in the stack
void display(Stack *s) {
    if (isQueueEmpty(&s->q1)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = s->q1.front; i <= s->q1.rear; i++) {
        printf("%d ", s->q1.arr[i]);
    }
    printf("\n");
}

// Menu-driven main function
int main() {
    Stack s;
    initStack(&s);

    int choice, value;
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top Element)\n");
        printf("4. Check if Empty\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = top(&s);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                if (isStackEmpty(&s)) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty.\n");
                }
                break;
            case 5:
                display(&s);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
