#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head, *current, *newNode;

struct node *create(){
    int data, ch=1;
    head=NULL;
    while(ch){
        printf("Enter the data: ");
        scanf("%d", &data);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;

        if(head==NULL){
            head = newNode;
            current = newNode;
        }
        else{
            current->next = newNode;
            current = newNode;
        }

        printf("Want to insert more data(1/0): ");
        scanf("%d", &ch);
    }

    return head;
}

void deleteFirst(){
    if(head==NULL){
        printf("\nList is empty...");
        exit(1);
    }
    current = head;
    head = head->next;
    free(current);
}

void deleteLast(){
    struct node *prev;
    current = head;

    while(current->next!=NULL){
        prev = current;
        current = current->next;
    }

    if(current == head) //means list have only one node
        head = NULL;
    else
        prev->next = NULL;

    free(current);
   
}

void deletePosition(){
    int pos, i=1;
    struct node *temp;

    current = head;
    printf("\nEnter the position which you want to delete data: ");
    scanf("%d", &pos);

    if(pos==1){
        temp = head;
        head = head->next;
    }
    else{
    
        while(i < pos-1){
            current = current->next;
            i++;
        }
        temp = current->next;
        current->next = temp->next;
    }
    free(temp);
}

void display(){
    current = head;
    while(current!=NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL");
}

void main(){

    head = create();
    display();

    // deleteFirst();
    // printf("\nDeleted first node\n");
    // display();

    // deleteLast();
    // printf("\nDeleted last node\n");
    // display();
    
    deletePosition();
    display();
}