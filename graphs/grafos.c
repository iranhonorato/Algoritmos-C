#include <stdlib.h>
#include <math.h>



typedef struct {
    int V; 
    double **edges; 
} graph_t;


graph_t *graph_create(int V, int weighted) {
    graph_t *new_graph;
    new_graph = malloc(sizeof(graph_t));

    new_graph->V = V;

    new_graph->edges = malloc(V * sizeof(double *));

    for (int i = 0; i < V; i++) {
        new_graph->edges[i] = malloc(V * sizeof(double));

        for (int j = 0; j < V; j++) {
            if (weighted) {
                new_graph->edges[i][j] = INFINITY;
            } else {
                new_graph->edges[i][j] = 0.0;
            }
        }
    }
    
    return new_graph;
}