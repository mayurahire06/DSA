#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int val) {
    Node *n = malloc(sizeof(Node));
    if (!n) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

//create tree from preorder input //eg: 1 2 -1 -1 3 -1 -1
//here -1 means NULL node

Node* buildTree() {
    int x;
    if (scanf("%d", &x) != 1) return NULL; // stop on EOF or invalid input //when input is not an integer then return NULL
    if (x == -1) return NULL;
    
    Node *root = createNode(x);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

/* Traversals */
void preorder(Node *root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* Free tree */
void freeTree(Node **root) {
    if (!root || !*root) return;
    freeTree(&((*root)->left));
    freeTree(&((*root)->right));
    free(*root);
    *root = NULL; // avoid dangling pointer
}

int main() {
    printf("Enter node values in preorder, use -1 for NULL (space-separated or newline). End with EOF:\n");
    Node *root = buildTree();

    printf("\nPreorder:  ");
    preorder(root);
    printf("\nInorder:   ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");

    freeTree(&root);
    return 0;
}



/* Build tree from preorder input:
   Read an integer. If it's -1, return NULL.
   Otherwise create node and recursively build left and right subtrees.
   Example input for tree:
     1 2 -1 -1 3 -1 -1
   This builds:
       1
      / \
     2   3
*/