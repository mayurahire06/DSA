#include <stdio.h> 
#include <stdlib.h>
#define MAX 5

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;
int currentSize = 0;

void push(int value) {
    struct node *newNode;

    if (currentSize == MAX) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }

    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    currentSize++;
    printf("Pushed %d into the stack\n", value);
}

void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop\n");
        return;
    }
    temp = top;
    printf("Popped %d from the stack\n", temp->data);
    top = top->next;
    free(temp);
    currentSize--;
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return top->data;
    }
}

int isEmpty() {
    return top == NULL;
}

int isFull() {
    return currentSize == MAX;
}

void display() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.isEmpty\n5.isFull\n6.Display Stack\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to push: ");
                scanf("%d", &value);
                if (isFull()) {
                    printf("Stack is full\n");
                } else {
                    push(value);
                }
                break;

            case 2:
                pop();
                break;

            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is: %d\n", value);
                }
                break;

            case 4:
                if (isEmpty()) {
                    printf("\nStack is empty\n");
                } else {
                    printf("\nStack is NOT empty\n");
                }
                break;
            
            case 5:
                if (isFull()) {
                    printf("\nStack is Full\n");
                } else {
                    printf("\nStack is NOT Full\n");
                }
                break;

            case 6:
                display();
                break;

            case 7:
                exit(0);
            
            default: printf("Invalid choice! Please try again.\n");
        }
    }
}
