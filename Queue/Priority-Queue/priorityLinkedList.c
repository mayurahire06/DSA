#include <stdio.h>
#include <stdlib.h>

// Node structure for the priority queue
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// Function prototypes
Node createNode(int data, int priority);
void enqueue(Node** head, int data, int priority);
int dequeue(Node** head);
int peek(Node* head);
void displayQueue(Node* head);
int isQueueEmpty(Node* head);

// Create a new node
Node createNode(int data, int priority) {
    Node newNode;
    newNode.data = data;
    newNode.priority = priority;
    newNode.next = NULL;
    return newNode;
}

// Enqueue operation (insert based on priority)
void enqueue(Node** head, int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    *newNode = createNode(data, priority);

    // If the list is empty or the new node has the highest priority
    if (*head == NULL || (*head)->priority < priority) {
        newNode->next = *head;
        *head = newNode;
        printf("Enqueued %d with priority %d.\n", data, priority);
        return;
    }

    // Traverse the list and find the correct position
    Node* temp = *head;
    while (temp->next != NULL && temp->next->priority >= priority) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Enqueued %d with priority %d.\n", data, priority);
}

// Dequeue operation (remove the highest priority element)
int dequeue(Node** head) {
    if (isQueueEmpty(*head)) {
        printf("Priority Queue is empty! Cannot dequeue.\n");
        return -1;
    }

    Node* temp = *head;
    int value = temp->data;
    *head = (*head)->next;
    free(temp);

    return value;
}

// Peek operation (get the element with the highest priority)
int peek(Node* head) {
    if (isQueueEmpty(head)) {
        printf("Priority Queue is empty! No element to peek.\n");
        return -1;
    }

    return head->data;
}

// Display all elements in the priority queue
void displayQueue(Node* head) {
    if (isQueueEmpty(head)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue contents:\n");
    printf("Value  Priority\n");
    while (head != NULL) {
        printf("%5d  %8d\n", head->data, head->priority);
        head = head->next;
    }
}

// Check if the priority queue is empty
int isQueueEmpty(Node* head) {
    return (head == NULL);
}

// Main function for menu-driven program
int main() {
    Node* priorityQueue = NULL;  // Head of the priority queue

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
                enqueue(&priorityQueue, value, priority);
                break;
            case 2:
                value = dequeue(&priorityQueue);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
            case 3:
                value = peek(priorityQueue);
                if (value != -1) {
                    printf("Element with highest priority: %d\n", value);
                }
                break;
            case 4:
                displayQueue(priorityQueue);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
