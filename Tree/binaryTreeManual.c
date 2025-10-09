#include <stdio.h>
#include <stdlib.h>

// Define structure for a Binary Tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inorder traversal: Left → Root → Right
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal: Root → Left → Right
void preorder(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal: Left → Right → Root
void postorder(Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    /*
        Manually creating this Binary Tree:

                1
              /   \
             2     3
            / \   / 
           4   5 6  
    */

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    printf("Inorder Traversal   : ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal  : ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal : ");
    postorder(root);
    printf("\n");

    return 0;
}
