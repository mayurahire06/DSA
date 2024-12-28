#include <stdio.h>
#include <stdlib.h>

const int MAX = 10; // Size of the priority queue

// Structure for a priority queue
typedef struct PriorityQueue {
    int *data;
    int *priority;
    int size;
    int capacity;
} PriorityQueue;

// Function prototypes
void initializeQueue(PriorityQueue *pq);
int isQueueEmpty(PriorityQueue *pq);
int isQueueFull(PriorityQueue *pq);
void enqueue(PriorityQueue *pq, int value, int priority);
int dequeue(PriorityQueue *pq);
int peek(PriorityQueue *pq);
void displayQueue(PriorityQueue *pq);

// Initialize the priority queue
void initializeQueue(PriorityQueue *pq) {
    pq->size = 0;
    pq->capacity = MAX;
    pq->data = (int *)malloc(pq->capacity * sizeof(int));
    pq->priority = (int *)malloc(pq->capacity * sizeof(int));
}

// Check if the priority queue is empty
int isQueueEmpty(PriorityQueue *pq) {
    return (pq->size == 0);
}

// Check if the priority queue is full
int isQueueFull(PriorityQueue *pq) {
    return (pq->size == pq->capacity);
}

// Enqueue an element with a priority
void enqueue(PriorityQueue *pq, int value, int priority) {
    if (isQueueFull(pq)) {
        printf("Priority Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    pq->data[pq->size] = value;
    pq->priority[pq->size] = priority;
    pq->size++;
    printf("Enqueued %d with priority %d.\n", value, priority);
}

// Dequeue the element with the highest priority
int dequeue(PriorityQueue *pq) {
    if (isQueueEmpty(pq)) {
        printf("Priority Queue is empty! Cannot dequeue.\n");
        return -1;
    }

    // Find the index of the element with the highest priority
    int highestPriorityIndex = 0;
    for (size_t i = 1; i < pq->size; i++) {
        if (pq->priority[i] > pq->priority[highestPriorityIndex]) {
            highestPriorityIndex = i;
        }
    }

    // Get the value to be dequeued
    int value = pq->data[highestPriorityIndex];

    // Shift elements to fill the gap
    for (size_t i = highestPriorityIndex; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    pq->size--;
    return value;
}

// Peek the element with the highest priority
int peek(PriorityQueue *pq) {
    if (isQueueEmpty(pq)) {
        printf("Priority Queue is empty! No element to peek.\n");
        return -1;
    }

    int highestPriorityIndex = 0;
    for (size_t i = 1; i < pq->size; i++) {
        if (pq->priority[i] > pq->priority[highestPriorityIndex]) {
            highestPriorityIndex = i;
        }
    }
    return pq->data[highestPriorityIndex];
}

// Display all elements in the priority queue
void displayQueue(PriorityQueue *pq) {
    if (isQueueEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue contents:\n");
    printf("Value  Priority\n");
    for (size_t i = 0; i < pq->size; i++) {
        printf("%5d  %8d\n", pq->data[i], pq->priority[i]);
    }
}

// Main function to implement the menu-driven program
int main() {
    PriorityQueue pq;
    initializeQueue(&pq);

    int choice, value, priority;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                printf("Enter priority of the value: ");
                scanf("%d", &priority);
                enqueue(&pq, value, priority);
                break;
            case 2:
                value = dequeue(&pq);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
            case 3:
                value = peek(&pq);
                if (value != -1) {
                    printf("Element with highest priority: %d\n", value);
                }
                break;
            case 4:
                displayQueue(&pq);
                break;
            case 5:
                printf("Exiting program.\n");
                free(pq.data);
                free(pq.priority);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
