#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* create() {
    int n, data;
    struct Node* head = NULL;
    struct Node* current = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    return head;
}

// Function to display the linked list
void display(struct Node* head) {
    printf("Linked list:\n");
    struct Node* current = head;
    int count = 0;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
        count++;
    }
    printf("NULL\n");
}

// Insert a node at a specific position in the linked list
struct Node* insertion(struct Node* head, int data, int position) {
    struct Node* current = head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position out of bounds. Node will not be inserted.\n");
        free(newNode);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

// Function to free all the nodes in the linked list
void freeNode(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int key, position;

    head = create();
    display(head);

    printf("Enter the position where you want to insert the data: ");
    scanf("%d", &position);

    printf("Enter the data to insert: ");
    scanf("%d", &key);

    head = insertion(head, key, position);
    display(head);

    freeNode(head);

    return 0;
}
