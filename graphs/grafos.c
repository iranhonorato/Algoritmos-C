#include <stdlib.h>
#include <math.h>



// Struct para o nosso grafo
typedef struct {
    int V; // Number of vertices
    double **edges; // array of arrays with data (matrix)
} graph_t;


graph_t *graph_create(int V, int weighted) {
    // 1. Alocamos o espaço para a estrutura principal do grafo
    graph_t *new_graph;
    new_graph = malloc(sizeof(graph_t));

    // 2. Definimos o número de vértices
    new_graph->V = V;

    // 3. Alocamos o array de ponteiros (as linhas da matriz)
    // Cada elemento aqui será um double* que aponta para uma linha completa
    new_graph->edges = malloc(V * sizeof(double *));

    // 4. Para cada linha, alocamos um array de doubles (as colunas)
    for (int i = 0; i < V; i++) {
        new_graph->edges[i] = malloc(V * sizeof(double));

        // 5. Inicialização dos valores
        for (int j = 0; j < V; j++) {
            if (weighted) {
                // Se o grafo tem peso, começamos com INFINITY (sem conexão
                new_graph->edges[i][j] = INFINITY;
            } else {
                // Se não tem peso (binário), começamos com 0 (sem conexão)
                new_graph->edges[i][j] = 0.0;
            }
        }
    }
    
    return new_graph;
}