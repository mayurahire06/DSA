#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *create(){
    int data, n, i;
    Node *head=NULL, *current, *newNode;

    printf("\nHow many Nodes: ");
    scanf("%d", &n);

    printf("\nEnter the data:\n");
    for(i=0; i<n; i++){
        newNode = (Node*)malloc(sizeof(Node));

        if(newNode == NULL){
            printf("\nMemory allocation is failed\n");
            exit(1);
        }

        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            current = newNode;
        }
        else{
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

void display(Node *current){

    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

Node *reverse(Node *head){
    Node *prevNode = NULL;
    Node *currNode = head;
    Node *nextNode = NULL;

    while(currNode != NULL){
        nextNode = currNode->next; 
        currNode->next = prevNode;
        prevNode = currNode;       
        currNode = nextNode;      
    }
    head = prevNode;

    return head;
}


int main(){
    Node *head;
    head = create();
    display(head);
    head = reverse(head);
    display(head);

    return 0;

}

