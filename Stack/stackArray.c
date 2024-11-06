#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1; 

void push(int value){
    if(top == MAX - 1){
        printf("Stack Overflow! Cannot push %d\n", value);
    }else{
        stack[++top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

void pop(){
    if(top == -1){
        printf("Stack Underflow! Cannot pop\n");
    }else{
        printf("Popped %d from the stack\n", stack[top--]);
    }
}

int peek(){
    if(top == -1){
        printf("Stack is empty\n");
        return -1;
    }else{
        return stack[top];
    }
}

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX - 1;
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }else{
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, value;

    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.isEmpty\n5.isFull\n6.Display Stack\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("\nEnter the number to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                value = peek();
                if(value != -1){
                    printf("Top element is: %d\n", value);
                }
                break;

            case 4:
                if(isEmpty()){
                    printf("\nStack is empty");
                }
                else{
                    printf("\nStack is not empty");
                }
                break;

            case 5:
                if(isFull()){
                    printf("\nStack is full");
                }
                else{
                    printf("\nStack is not full");
                }
                break;

            case 6:
                display();
                break;

            case 7:
                printf("\nExiting program.");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
}
