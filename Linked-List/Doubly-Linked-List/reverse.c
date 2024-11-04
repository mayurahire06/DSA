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

Node *reverse(Node *head){
    Node *prevNode = NULL;
    Node *currNode = head;
    Node *nextNode = NULL;
    
    while (currNode != NULL){
        nextNode = currNode->next;
        
        // Check if nextNode is not NULL before assigning its prev
        if (nextNode != NULL){
            nextNode->prev = currNode;
        }
  
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    head = prevNode;
    return head;
}

void freeNode(Node *head){
    Node *temp;
    while(head != NULL){
        temp = head->next;
        free(head);
        head = temp;
    }
}

int main(){
    Node *head = create();
    display(head);
    printf("\nAfter reversing:\n");
    head = reverse(head);
    display(head);

    freeNode(head);
    return 0;
}