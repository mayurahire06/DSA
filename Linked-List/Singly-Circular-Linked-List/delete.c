#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *create(){
    int data, n;
    Node *head=NULL, *temp, *newNode;
    
    printf("\nHow many nodes: ");
    scanf("%d", &n);

    printf("\nEnter the data:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
    }

    if(temp !=  NULL){
        temp->next = head;
    }

    return head;
}

void display(Node* head) {
    Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

Node *deleteFirst(Node *head){
    Node *temp=head;

    if(head == NULL){
        printf("\nList is empty");
        return head;
    }

    // If there is only one node in the circular linked list
    if (head->next == head) {
        free(head);
        return NULL;
    }

    Node *current=head;
    while(current->next !=  head){
        current = current->next;
    }

    head = head->next;
    current->next = head;
    free(temp);

    return  head;
}

void deleteLast(Node *head){
    Node *temp, *current;

    if(head == NULL){
        printf("\nList is empty");
        return;
    }

    if(head->next == head){
        free(head);
        return;
    }

    temp = head;
     while(temp->next !=  head){
        current =  temp;
        temp = temp->next;
    }

    current->next = head;
    free(temp);
}

Node *deletePosition(Node *head){
    int pos, count = 1;
    Node *temp, *current = head;

    printf("\nEnter the position: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("\nList is empty");
        return NULL;
    }

    if (pos == 1) {
        if (head->next == head) {  
            free(head);
            return NULL;           
        }

        temp = head;
        head = head->next;

        while (current->next != head) {
            current = current->next;
        }

        current->next = head;

        free(temp);
        return head;
    } else {
        while (current->next != head && count < pos - 1) {
            current = current->next;
            count++;
        }

        if (current->next == head) {
            printf("\nPosition out of bounds");  
            return head;
        }

        temp = current->next;
        current->next = temp->next;
        free(temp);

        return head;
    }
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

int main(){
    Node *head;

    head = create();
    display(head);
    // printf("\nAfter deleting first node:\n");
    // head = deleteFirst(head);
    // display(head);

    // printf("\nAfter deleting last node:\n");
    // deleteLast(head);
    // display(head);

    head = deletePosition(head);
    printf("\n");
    display(head);

    freeNode(head);
    return 0;
}