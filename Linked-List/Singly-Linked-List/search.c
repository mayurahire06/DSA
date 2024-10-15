#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create the linked list
struct Node *create() {
    int n, data;
    struct Node* head = NULL;
    struct Node* current = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("No nodes to create.\n");
        return NULL;
    }

    printf("Enter the nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        newNode->data = data;
        newNode->next = NULL;

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
void display(struct Node* current) {
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list:\n");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the linked list
void search(int x, struct Node* current) {
    while (current != NULL) {
        if (current->data == x) {
            printf("%d found in the linked list\n", x);
            return;
        }
        current = current->next;
    }
    printf("%d is NOT found in the linked list\n", x);
}

// Function to free the nodes in the linked list


int main() {
    int x;
    struct Node *head;

    head = create();

    if (head != NULL) {
        display(head);
        printf("\nEnter the data you want to search: ");
        scanf("%d", &x);
        search(x, head);
        freeNode(head);
    }

    return 0;
}
