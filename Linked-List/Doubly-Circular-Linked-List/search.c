#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
} Node;

Node *create() {
    int n, data;
    Node *head = NULL, *temp, *newNode;

    printf("\nHow many nodes: ");
    scanf("%d", &n);

    printf("\nEnter the data:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Make the list circular
    if (head != NULL) {
        temp->next = head;
        head->prev = temp;
    }

    return head;
}

void display(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

void search(Node *head) {
    int data;
    Node *temp = head;
    if (head == NULL) {
        printf("List is empty. Cannot search.\n");
        return;
    }

    printf("\nEnter the data to be searched: ");
    scanf("%d", &data);

    do {
        if (temp->data == data) {
            printf("Data is found!\n");
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Data NOT found!\n");
}

void freeNode(Node *head) {
    if (head == NULL) return;

    Node *temp = head;
    Node *nextNode;

    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
}

int main() {
    Node *head = create();
    printf("Original linked list:\n");
    display(head);

    search(head);

    freeNode(head);
    return 0;
}
