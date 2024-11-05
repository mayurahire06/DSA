#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
} Node;

Node *create() {
    int n;
    Node *head = NULL, *temp, *newNode;

    printf("\nHow many nodes: ");
    scanf("%d", &n);

    printf("\nEnter the data:\n");
    for (int i = 0; i < n; i++) {
        newNode = (Node *)malloc(sizeof(Node));
        scanf("%d", &newNode->data);
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

    if (temp != NULL) {
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
    printf("\n");
}

Node *reverse(Node *head) {
    if (head == NULL || head->next == head) {
        return head;
    }

    Node *prevNode = NULL;
    Node *currNode = head;
    Node *nextNode = NULL;

    do {
        nextNode = currNode->next;
        currNode->next = prevNode;
        currNode->prev = nextNode;
        prevNode = currNode;
        currNode = nextNode;
    } while (currNode != head);

    head->next = prevNode;
    prevNode->prev = head;

    return prevNode;
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

    head = reverse(head);
    printf("\nAfter reversing linked list:\n");
    display(head);

    freeNode(head);
    return 0;
}
