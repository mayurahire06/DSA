#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node *create(){
    int n, data;
    Node *head = NULL, *temp, *newNode;

    printf("\nHow many nodes: ");
    scanf("%d", &n);

    printf("\nEnter the data:\n");
    for(int i = 0; i < n; i++){
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

    if(temp != NULL){
        temp ->next = head;
    }

    return head;
}

void display(Node *head){
    Node *temp = head;
     if (head == NULL) {      
        printf("List is empty\n");
        return;
    }
    
    while(temp->next != head){
        printf("%d ",  temp->data);
        temp = temp->next;
    }
    printf("%d ",  temp->data);
}

void search(Node *head){
    int data, flag = 0;
    Node *temp = head;

    printf("\nEnter the data to be searched: ");
    scanf("%d", &data);

    do{
        if(temp->data == data){
            printf("Data is found!!!");
            return;
        }
        temp = temp->next;
    }while(temp!= head);

    printf("Data NOT found!!!");    
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
    Node* head = NULL;

    head = create();
    display(head);
    search(head);
    
    freeNode(head);
    return 0;
}