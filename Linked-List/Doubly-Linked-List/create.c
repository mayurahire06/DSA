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

void display(Node *temp){
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
 
    printf("NULL");
}

int main(){
    Node *head;

    head = create();
    display(head);

    return 0;
}