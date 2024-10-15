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
    printf("Linked list:\n");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the nodes in the linked list
void freeNode(struct Node* current) {
    while (current != NULL) {
        struct Node* temp = current;  
        current = current->next;     
        free(temp);                  
    }
}

int main() {
    struct Node *head;

    head = create();
    display(head);
    freeNode(head);

    return 0;
}
