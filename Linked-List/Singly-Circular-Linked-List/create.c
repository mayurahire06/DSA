#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *create(){
    int data, n;
    Node *head=NULL, *current, *newNode;
    
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
            current = newNode;
        }
        else{
            current->next = newNode;
            current = newNode;
        }
    }

    // Make the list circular by connecting the last node to the head
    if (current != NULL) {
        current->next = head;
    }

    return head;
}

void display(Node *head){
    Node *current = head;

    while(current->next != head){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("%d", current->data);
}

int main(){
    Node *head;

    head = create();
    display(head);

    return 0;
}