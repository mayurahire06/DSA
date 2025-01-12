#include <stdio.h>
#define NODES 10

int graph[NODES][NODES];
int visited[NODES];         
int nodes;

typedef struct {
    int data[NODES];
    int top;
} Stack;

void push(Stack *stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        return -1; 
    }
    return stack->data[stack->top--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void dfsUsingStack(int start) {
    Stack stack;
    stack.top = -1;

    push(&stack, start);
    while (!isEmpty(&stack)) {
        int current = pop(&stack);

        if (!visited[current]) {
            visited[current] = 1;
            printf("%d ", current); 

            for (int i = nodes - 1; i >= 0; i--) { // Reverse order for correct DFS
                if (graph[current][i] == 1 && !visited[i]) {
                    push(&stack, i);
                }
            }
        }
    }
}

int main() {
    int edges, u, v;
    int start;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    printf("Enter the starting node for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfsUsingStack(start);

    return 0;
}
