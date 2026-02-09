#include <stdio.h>
#include <stdbool.h>

#define INF 9999
#define MAX 50

// Function to find the vertex with the minimum distance value
int get_min_distance(int dist[], bool visited[], int n) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the path from source to a given vertex
void print_path(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    print_path(parent, parent[j]);
    printf(" -> %d", j);
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];    
    bool visited[MAX]; 
    int parent[MAX];  

    // Initialization
    for (int i = 0; i < n; i++) {
        parent[src] = -1;
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;
    parent[src] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = get_min_distance(dist, visited, n);
        
        if (u == -1) break; // All reachable nodes processed
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            // Update dist[v] only if it is not visited, there is an edge,
            // and the total weight of path from src to v through u is smaller than current value
            if (!visited[v] && graph[u][v] && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array and paths
    printf("\n%-10s %-10s %-20s", "Vertex", "Distance", "Path");
    printf("\n--------------------------------------------");
    for (int i = 0; i < n; i++) {
        printf("\n%d -> %-4d | ", src, i);
        if (dist[i] == INF) {
            printf("%-8s | %-20s", "INF", "No Path");
        } else {
            printf("%-8d | ", dist[i]);
            print_path(parent, i);
        }
    }
    printf("\n");
}

int main() {
    int n, edges, u, v, w, source;
    int graph[MAX][MAX] = {0};

    printf("--- Dijkstra's Shortest Path Algorithm ---\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges in format (source destination weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        if (u < n && v < n) {
            graph[u][v] = w; // Use graph[v][u] = w for undirected
        }
    }

    printf("Enter the starting source node: ");
    scanf("%d", &source);

    if (source >= 0 && source < n) {
        dijkstra(graph, n, source);
    } else {
        printf("Invalid source node!\n");
    }

    return 0;
}