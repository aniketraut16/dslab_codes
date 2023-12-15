#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 100

struct City {
    char name[50];
};

struct Graph {
    int vertices;
    int** distanceMatrix;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->distanceMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->distanceMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->distanceMatrix[i][j] = INT_MAX;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int distance) {
    graph->distanceMatrix[src][dest] = distance;
    graph->distanceMatrix[dest][src] = distance;
}

void printMatrix(struct Graph* graph) {
    printf("\nDistance Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->distanceMatrix[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", graph->distanceMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

void shortestPath(struct Graph* graph, int src, int dest) {
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
            if (!visited[v] && graph->distanceMatrix[minIndex][v] &&
                distance[minIndex] != INT_MAX &&
                distance[minIndex] + graph->distanceMatrix[minIndex][v] < distance[v]) {
                distance[v] = distance[minIndex] + graph->distanceMatrix[minIndex][v];
            }
        }
    }

    printf("\nShortest distance from %d to %d: %d\n", src, dest, distance[dest]);

    free(distance);
    free(visited);
}

int main() {
    int cities, edges, src, dest, distance;
    int choice;

    printf("Enter the number of cities in the graph: ");
    scanf("%d", &cities);

    struct Graph* graph = createGraph(cities);

    printf("Enter the number of connections between cities: ");
    scanf("%d", &edges);

    printf("Enter city names:\n");
    struct City city[MAX_CITIES];
    for (int i = 0; i < cities; i++) {
        printf("City %d: ", i + 1);
        scanf("%s", city[i].name);
    }

    printf("Enter the connections (source destination distance):\n");
    for (int i = 0; i < edges; i++) {
        printf("Connection %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &distance);
        addEdge(graph, src, dest, distance);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Display Distance Matrix\n");
        printf("2. Find Shortest Path\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printMatrix(graph);
                break;
            case 2:
                printf("Enter source and destination cities (indices): ");
                scanf("%d %d", &src, &dest);
                shortestPath(graph, src, dest);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}

