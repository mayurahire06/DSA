#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1 || front > rear;
}

int isFull() {
    return rear == SIZE - 1;
}

void enqueue(int value){
    if(isFull()){
        printf("Queue is full\n");
    } 
    else{
        if(front == -1) 
            front = 0;
        // rear++;
        queue[++rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

int peek(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        return queue[front];
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty\n");
    } 
    else{
        printf("%d dequeued from queue\n", queue[front++]);
        // front++;
        if(front > rear){
            front = rear = -1; // Reset the queue when empty
        }
    }
}

void display() {
    if(isEmpty()){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements: ");
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, value;
    while(1){
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
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
                    printf("Peek element: %d\n", value);
                }
                break;

            case 4:
                if(isEmpty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;

            case 5:
                if(isFull())
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
