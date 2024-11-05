#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev, *next;
}Node;

Node *create(){
    int n, data;
    Node *head = NULL, *temp=NULL, *newNode=NULL;
    printf("\nHow many nodes: ");
    scanf("%d", &n);

    printf("\nEnter the data:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    if(temp != NULL){
        temp->next = head;
        head->prev = temp;
    }

    return head;
}

void display(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

Node *insertFirst(Node *head){
    Node *temp=head;
    Node *newNode = (Node*)malloc(sizeof(Node));
    printf("\nEnter the data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL){ 
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return head;
    }

    while(temp->next != head){
        temp = temp->next;
    }

    newNode->next = head;
    head->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    head = newNode;

    return head;
}

Node *insertLast(Node *head){
    Node *temp = head;
    Node *newNode = (Node*)malloc(sizeof(Node));
    printf("\nEnter the data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL){ 
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return head;
    }

    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;

    return head;
}

Node *insertPosition(Node *head){
    int pos, count = 1;
    Node *temp = head;
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head; 
    }

    printf("\nEnter the data: ");
    scanf("%d", &newNode->data);

    printf("\nEnter the position: ");
    scanf("%d", &pos);

    // Inserting at the beginning
    if (pos == 1){
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
        return head;
    }

    // Traverse to find the position
    while (temp->next != head && count < pos - 1){
        temp = temp->next;
        count++;
    }

    // Check if we reached back to head and count is less than pos - 1
    if (temp->next == head && count < pos - 1){
        printf("\n position is out of range");
        free(newNode);
        return head;
    }

    // Insert in the middle or at the end
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

void freeNode(Node *head) {
    if (head == NULL) return;

    Node *temp = head;
    do{
        Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
}

int main(){
    Node *head = create();
    display(head);

    // printf("\nAfter inserting at the beginning\n");
    // head = insertFirst(head);
    // display(head);
    
    // printf("\nAfter inserting at the last\n");
    // head = insertLast(head);
    // display(head);

    printf("\nAfter inserting at position\n");
    head = insertPosition(head);
    display(head);

    freeNode(head);
    return 0;
}