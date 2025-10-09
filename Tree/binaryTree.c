#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Define the structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Simple queue structure for level-order insertion
typedef struct Queue {
    Node* data[MAX];// Array to hold pointers to nodes, means every element in the queue is a pointer to a Node
    int front, rear;
} Queue;


// Create a new node
Node* createNode(int value) {
    if (value == -1) return NULL;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow!\n");
        return;
    }

    if (q->front == -1)  // First element
        q->front = 0;

    q->data[++q->rear] = node;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow!\n");
        return NULL;
    }

    Node* temp = q->data[q->front++];
    if (q->front > q->rear)  // Reset queue
        q->front = q->rear = -1;

    return temp;
}

// Build the binary tree from user input
Node* buildTree() { //here we are using which king of queue? queue of pointers to Nodes //because each element of the queue is a pointer to a Node
    int val;
    printf("Enter root value (-1 for NULL): ");
    scanf("%d", &val);

    Node* root = createNode(val);
    if (root == NULL) return NULL;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);

        printf("Enter left child of %d (-1 for NULL): ", current->data);
        scanf("%d", &val);
        current->left = createNode(val);
        if (current->left) enqueue(&q, current->left);

        printf("Enter right child of %d (-1 for NULL): ", current->data);
        scanf("%d", &val);
        current->right = createNode(val);
        if (current->right) enqueue(&q, current->right);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal
void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    Node* root = buildTree();

    printf("\nInorder Traversal   : ");
    inorder(root);

    printf("\nPreorder Traversal  : ");
    preorder(root);

    printf("\nPostorder Traversal : ");
    postorder(root);

    return 0;
}
