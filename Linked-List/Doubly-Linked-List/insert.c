#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev, *next;
}Node;

Node *create(){
    int n, data;
    Node *head=NULL, *temp, *newNode;

    printf("\nHow many nodes: ");
    scanf("%d", &n);

    printf("\nEnter the data:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        newNode->prev = NULL;
        newNode->data = data;
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
    return head;
}

void display(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

Node *insertFirst(Node *head){
    int data;
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){ 
        printf("Memory allocation failed\n");
        return head;  
    }
    printf("\nEnter the data: ");
    scanf("%d", &data);
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = head;

    head->prev = newNode;
    head = newNode;

    return head;
}

void insertLast(Node *head){
    Node *temp=head, *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("\nEnter the data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;

     // If the list is empty, the new node becomes the head
    if (head == NULL) {
        head = newNode;
        return;
    }

    while(temp->next != NULL){
        temp =  temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

}

Node *insertPosition(Node *head){
    int  data, pos, count=1;
    Node *temp=head, *current, *newNode;

    newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return head;
    }
    printf("\nEnter the data: ");
    scanf("%d", &data);

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    printf("\nEnter the position for the data: ");
    scanf("%d", &pos);

    if (pos == 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    else{

        while(temp != NULL && count < pos-1){
            temp = temp->next;
            count++;
        }

        if(temp == NULL){
            printf("Position is out of range\n");
            free(newNode);
            return head;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        
        if (temp->next != NULL){ // Maintain doubly linked structure
            temp->next->prev = newNode;
        }

        temp->next = newNode;
        return head;
    }
}

void freeNode(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head->next;  // Save the next node
        free(head);          // Free the current node
        head = temp;         // Move to the next node
    }
}

void main(){
    Node *head;

    head = create();
    display(head);
    // head = insertFirst(head);
    // display(head);
    // insertLast(head);
    // display(head);
    head = insertPosition(head);
    display(head);
    freeNode(head);
}