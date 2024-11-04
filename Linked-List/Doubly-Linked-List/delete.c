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
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head ==  NULL){
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
    Node *temp=head;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

Node *deleteFirst(Node *head){
    Node *temp = head;
    if(head == NULL)
        return head;

    head = head->next;
    free(temp);
    return head;
}

void deleteLast(Node *head) {
    Node *temp = head, *current;

    if (head == NULL) {  
        printf("List is already empty.\n");
        return;
    }

    if (temp->next == NULL) {  
        free(temp);
        head = NULL; 
        return;
    }

    while (temp->next != NULL) {
        current = temp;
        temp = temp->next;
    }

    // Update the second-last node's next pointer to NULL
    current->next = NULL;  
    free(temp);
}

Node *deletePosition(Node *head){
    int pos, count = 1;
    Node *temp = head, *current = NULL;

    printf("\nEnter the position: ");
    scanf("%d", &pos);

    if (head == NULL){
        printf("The list is empty.\n");
        return head;
    }

    if (pos == 1){
        head = head->next;
        if (head != NULL){
            head->prev = NULL;  // Update head's prev pointer if it's not NULL
        }
        free(temp);
        return head;
    }

    while (temp != NULL && count < pos - 1){
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL){
        printf("Position is out of range.\n");
        return head;
    }

    current = temp->next;
    temp->next = current->next;
    if (current->next != NULL){
        current->next->prev = temp;
    }

    free(current);
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
    // head = deleteFirst(head);
    // printf("\nDeleting after first node:\n");
    // display(head);

    // deleteLast(head);
    // printf("\nDeleting after last node:\n");
    // display(head);

    head = deletePosition(head);
    printf("\nDeleting after the position:\n");
    display(head);

    freeNode(head);
    return 0;
}