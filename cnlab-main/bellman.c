#include <stdio.h>
#include <limits.h>

#define MAX_NODES 10
#define INF 999

void bellmanFord(int graph[MAX_NODES][MAX_NODES], int nodes, int source) {
    int distance[MAX_NODES];
    int i, j, k;

    for (i = 0; i < nodes; i++)
        distance[i] = INF;
    distance[source] = 0;
    for (i = 0; i < nodes - 1; i++) {
        for (j = 0; j < nodes; j++) {
            for (k = 0; k < nodes; k++) {
                if (graph[j][k] != INF && distance[j] + graph[j][k] < distance[k]) {
                    distance[k] = distance[j] + graph[j][k];
                }
            }
        }
    }


    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            if (graph[i][j] != INF && distance[i] + graph[i][j] < distance[j]) {
                printf("Graph contains negative-weight cycle!\n");
                return;
            }
        }
    }

    printf("Shortest distances from source node %d:\n", source);
    for (i = 0; i < nodes; i++) {
        printf("Node %d: Distance = %d\n", i, distance[i]);
    }
}

int main() {
    int nodes, source, i, j;
    int graph[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the adjacency matrix (999 for no edge):\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // printf("Enter the source node: ");
    // scanf("%d", &source);
    for(int i=0;i<nodes;i++){
        bellmanFord(graph, nodes, i);
    }


    return 0;
}
