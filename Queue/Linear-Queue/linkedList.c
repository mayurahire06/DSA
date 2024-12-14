#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node *front = NULL;
Node *rear = NULL;

const int MAX = 5;
int currSize = 0;

int isEmpty(){
    return front == NULL;
}

int isFull(){
    return currSize == MAX;
}

void enqueue(int value){
    if(isFull()){
        printf("Queue is full\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL && rear == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
    currSize++; 
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty\n");
    }
    else{
        Node *temp = front;
        front = front->next;
        printf("\n%d is dequeue", temp->data);
        free(temp);
        currSize--;
    }
}

int peek(){
    if(front == NULL){
        printf("Queue is empty\n");
        return -1;
    } 
    else{
        return front->data;
    }
}

void display(){
    Node *temp = front;
    printf("\nQueue elements:\n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int choice, value;

    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.isEmpty\n5.isFull\n6.Display Queue\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
             case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                value = peek();
                if(value != -1){
                    printf("Peek element is: %d\n", value);
                }
                break;

            case 4:
                if(isEmpty()){
                    printf("\nQueue is empty\n");
                }
                else{
                    printf("\nQueue is NOT empty\n");
                }
                break;
            
            case 5:
                if(isFull()){
                    printf("\nQueue is Full\n");
                }
                else{
                    printf("\nQueue is NOT Full\n");
                }
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);

            default:
                printf("\nWrong choice!!!");
        }
    }
    return 0;
}