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

    if(temp != NULL){
        temp->next = head;
        head->prev = temp;
    }
    return head;
}

void display(Node *head){
    Node *temp=head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
}

Node *deleteFirst(Node *head) {
    if (head == NULL) return NULL;
    
    Node *temp = head; 

    if (head->next == head){ 
        free(temp);
        return NULL;
    }

    head = head->next; 
    head->prev = temp->prev;
    temp->prev->next = head;

    free(temp); 
    return head;
}

Node *deleteLast(Node *head) {
    if(head == NULL) return NULL; 
    if(head->next == head){
        free(head);
        return NULL;
    }

    Node *temp = head->prev;
    temp->prev->next = head; 
    head->prev = temp->prev; 
    free(temp);
    return head;
}

Node *deletePosition(Node *head){
    int pos, count = 1;
    Node *temp, *current = NULL;

    if (head == NULL) return NULL;

    printf("\nEnter the position: ");
    scanf("%d", &pos);

    temp = head;

    // Case when deleting the head node
    if (pos == 1) {
        if (head->next == head) { // Only one node in the list
            free(head);
            return NULL;
        }
        head = head->next;
        temp->prev->next = head;
        head->prev = temp->prev;
        free(temp);
        return head;
    } else {
        // Traverse to the node just before the target node
        while (temp->next != head && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        // Check if position is out of range
        if (temp->next == head && count < pos - 1) {
            printf("\nPosition is out of range!!!");
            return head;
        }

        // `current` should point to the node at `pos - 1`
        current = temp;
        temp = temp->next; // `temp` now points to the node to delete

        // Adjust the pointers to remove `temp`
        current->next = temp->next;
        temp->next->prev = current;
        free(temp);
        return head;
    }
}

void freeNode(Node *head) {
    if (head == NULL) return;

    Node *temp = head;
    Node *nextNode;

    do{
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }while (temp != head);
}

int main(){
    Node *head = create();
    display(head);
    // printf("\nDeleting after first node\n");
    // head = deleteFirst(head);
    // display(head);

    // printf("\nDeleting after last node\n");
    // head = deleteLast(head);
    // display(head);

    printf("\nDeleting after the position\n");
    head = deletePosition(head);
    display(head);

    freeNode(head);
    return 0;
}