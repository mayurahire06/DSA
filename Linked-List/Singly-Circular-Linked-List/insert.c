 #include<stdio.h>
 #include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node *create(){
    int n, data;
    Node *head=NULL, *temp, *newNode;

    printf("\nEnter the nodes: ");
    scanf("%d", &n);

    printf("\nEnter the nodes:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        newNode = (Node *)malloc(sizeof(Node));
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
        temp->next = head;
    }

    return head;
}

void display(Node *head){
    Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while(temp->next != head){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

Node* insertFirst(Node* head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("\nEnter the data for the new node: ");
    scanf("%d", &newNode->data);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    newNode->next = head;  
    head = newNode;   
    last->next = head;  

    return head;
}


Node* insertLast(Node *head) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    printf("\nEnter the data for the new node: ");
    scanf("%d", &newNode->data);

    if (head == NULL) {
        newNode->next = newNode;  
        return newNode;         
    }

    Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;  
    newNode->next = head;   
    return head;  
}

Node *insertPosition(Node *head) {
    int pos, count = 1;
    Node *newNode, *temp;

    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        return head;
    }

    printf("\nEnter the data for the new node: ");
    scanf("%d", &newNode->data);

    printf("Enter the position you want to insert data: ");
    scanf("%d", &pos);

    if (pos == 1){
        if (head == NULL){
            newNode->next = newNode;
            return newNode;
        } 
        else{
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            return newNode;
        }
    }
    else{
        temp = head;
        while (temp->next != head && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
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
    Node *head;

    head = create();
    display(head);

    // head = insertFirst(head);
    // display(head);

    // insertLast(head);
    // display(head);

    freeNode(head);
    head = insertPosition(head);
    display(head);

}