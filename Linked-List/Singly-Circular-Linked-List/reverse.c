#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node *create() {
    int n, data;
    Node *head = NULL, *temp, *newNode;

    printf("\nHow many nodes: ");
    scanf("%d", &n);

    printf("\nEnter the data:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    if (temp != NULL) {
        temp->next = head; // Make it circular
    }

    return head;
}

void display(Node *head) {
    Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

Node *reverse(Node *head) {
    Node *prevNode = NULL;
    Node *currNode = head;
    Node *nextNode = NULL;

    if (head == NULL || head->next == head) {
        return head; // Nothing to reverse
    }

    do {
        nextNode = currNode->next; 
        currNode->next = prevNode; 
        prevNode = currNode;       
        currNode = nextNode;         
    } while (currNode != head);     

    head->next = prevNode;          // The old head should now point to the new head
    head = prevNode;                // Update head to the new head

    return head;                   
}

void freeNode(Node *head){
    Node *temp;
    if (head == NULL) {
        return; 
    }

    temp = head;
    do{
        head = head->next;
        free(temp);
        temp = head;
    }while (temp != head);

    head = NULL; // Optional: set head to NULL to avoid dangling pointer
}

int main() {
    Node* head = NULL;

    head = create();
    display(head);
    printf("Reversed Linked List:\n");
    head = reverse(head);
    display(head);
    
    freeNode(head);
    return 0;
}
