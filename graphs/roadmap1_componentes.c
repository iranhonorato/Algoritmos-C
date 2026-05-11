#include "grafos.c"
#include <math.h>
#include <stdlib.h>

// gcc -Wall -Og -g -fsanitize=address graph.o test_graph.c dfs.c `pkg-config --cflags --libs check`
void dfs(grafo *G, int nodo_atual, int *componentes, int count) {
    if (componentes[nodo_atual] != -1) {
        return;
    }

    componentes[nodo_atual] = count;
    for (int prox_nodo = 0; prox_nodo < G->V; prox_nodo++) {
        if (G->edges[nodo_atual][prox_nodo] != 0 && G->edges[nodo_atual][prox_nodo] != INFINITY) {
            dfs(G, prox_nodo, componentes, count);
        }
    }

    return;
}

int conta_components(grafo *G, int *componentes) {
    for (int i = 0; i < G->V; i++) {
        componentes[i] = -1;
    }
    int count = 0;

    for (int nodo_atual = 0; nodo_atual < G->V; nodo_atual++) {
        if (componentes[nodo_atual] == -1) {
            dfs(G, nodo_atual, componentes, count);
            count++;
        } 
    }

    return count;
}
