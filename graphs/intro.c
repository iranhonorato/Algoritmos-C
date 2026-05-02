// Um grafo é uma estrutura de dados composta por nós (vértices) e conexões entre eles (arestas).
// Ao contrário de árvores, grafos podem ter ciclos, múltiplos caminhos entre nós,
// e até nós sem nenhuma conexão.

// Propriedades que definem um grafo:

// - Direcionado (dígrafo): as arestas têm sentido. A → B não implica B → A.
// - Não-direcionado: a conexão é simétrica. Se A conecta B, B conecta A.
// - Ponderado: cada aresta tem um peso (distância, custo, etc.).
// - Cíclico: existe pelo menos um caminho que volta ao nó de origem.
// - Acíclico: não existem ciclos. Um DAG (Directed Acyclic Graph) é o caso mais comum.
// - Conexo: existe um caminho entre qualquer par de nós.
// - Desconexo: alguns nós são inacessíveis a partir de outros.

#include <stdio.h>
#include <stdlib.h>
#include "grafos.c"

static void dfs_visita(grafo *g, int v, int *visitado) {
    visitado[v] = 1;

    for (int prox_nodo = 0; prox_nodo < g->V; prox_nodo++) {
        if (g->edges[v][prox_nodo] != 0.0 && !visitado[prox_nodo])
            dfs_visita(g, prox_nodo, visitado);
    }
}

void busca_em_profundidade(grafo *g) {
    int *visitado = malloc((g->V)*sizeof(int));

    for (int nodo_atual = 0; nodo_atual < g->V; nodo_atual++) {
        if (!visitado[nodo_atual])
            dfs_visita(g, nodo_atual , visitado);
    }

    free(visitado);
}


void busca_em_largura(grafo *grafo) {

}