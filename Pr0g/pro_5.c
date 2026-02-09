#include <stdio.h>

int matrix[10][10], visited[10], n;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (matrix[v][i] && !visited[i]) dfs(i);
}

void bfs(int start) {
    int q[10], f = 0, r = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;

    visited[start] = 1;
    q[r++] = start;

    while (f < r) {
        int v = q[f++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (matrix[v][i] && !visited[i]) {
                visited[i] = 1;
                q[r++] = i;
            }
        }
    }
}

int main() {
    n = 6; // Example: 6 vertices
    int edges[][2] = {{0,1}, {0,2}, {1,3}, {1,4}, {2,5}};
    
    for (int i = 0; i < 5; i++) {
        matrix[edges[i][0]][edges[i][1]] = 1;
        matrix[edges[i][1]][edges[i][0]] = 1;
    }

    printf("DFS Traversal: ");
    dfs(0);
    
    printf("\nBFS Traversal: ");
    bfs(0);
    printf("\n");

    return 0;
}