#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

struct Graph {
    int vertices;
    int** adjacencyMatrix;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->adjacencyMatrix[src][dest] = weight;
    graph->adjacencyMatrix[dest][src] = weight;
}

void dijkstra(struct Graph* graph, int src, int dest) {
    int* distance = (int*)malloc(graph->vertices * sizeof(int));
    int* visited = (int*)malloc(graph->vertices * sizeof(int));

    for (int i = 0; i < graph->vertices; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[src] = 0;

    for (int count = 0; count < graph->vertices - 1; count++) {
        int minDistance = INT_MAX;
        int minIndex = -1;

        for (int v = 0; v < graph->vertices; v++) {
            if (visited[v] == 0 && distance[v] <= minDistance) {
                minDistance = distance[v];
                minIndex = v;
            }
        }

        visited[minIndex] = 1;

        for (int v = 0; v < graph->vertices; v++) {
            if (!visited[v] && graph->adjacencyMatrix[minIndex][v] &&
                distance[minIndex] != INT_MAX &&
                distance[minIndex] + graph->adjacencyMatrix[minIndex][v] < distance[v]) {
                distance[v] = distance[minIndex] + graph->adjacencyMatrix[minIndex][v];
            }
        }
    }

    printf("Shortest distance from %d to %d: %d\n", src, dest, distance[dest]);

    free(distance);
    free(visited);
}

int main() {
    int vertices, edges, src, dest, weight;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    printf("Enter the source and destination nodes: ");
    scanf("%d %d", &src, &dest);

    dijkstra(graph, src, dest);

    return 0;
}
