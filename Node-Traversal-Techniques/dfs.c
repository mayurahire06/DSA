//Recursive DFS

#include <stdio.h>
#define NODES 10

int graph[NODES][NODES];
int visited[NODES];         
int nodes;                     

void dfs(int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < nodes; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(i);
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
    dfs(start);

    return 0;
}
