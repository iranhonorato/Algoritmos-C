#include <math.h>
#include <stdlib.h>


typedef struct {
    int V;
    double **path;
} grafo;



grafo *cria_grafo(int V, int weighted) {
    grafo *new_graph = malloc(sizeof(grafo));

    new_graph->V = V;

    double **path = malloc(V * sizeof(double *));
    new_graph->path = path;

    for (int i = 0; i < V; i++) {
        new_graph->path[i] = malloc(V * sizeof(double));

        for (int j = 0; j < V; j++) {
            if (weighted) {
                new_graph->path[i][j] = INFINITY;
            } else {
                new_graph->path[i][j] = 0.0;
            }
        }
    }

    return new_graph;
}

void apaga_grafo(grafo **G) {
    if (G == NULL || *G == NULL) return;

    grafo *g = *G;

    for (int i = 0; i < g->V; i++)
        free(g->path[i]);

    free(g->path);
    free(g);
    *G = NULL;
}

/* ---------------------------------------------------------------
 *  NAO DIRECIONADO — path[u][v] == path[v][u]
 *
 *  Exemplo 1: triangulo
 *
 *      0 --- 1
 *       \   /
 *        \ /
 *         2
 *
 *  Matriz:
 *      [0][1][2]
 *  [0]  0  1  1
 *  [1]  1  0  1
 *  [2]  1  1  0
 * --------------------------------------------------------------- */
grafo *exemplo_nao_direcionado_1(void) {
    grafo *g = cria_grafo(3, 0);
    g->path[0][1] = 1; g->path[1][0] = 1;
    g->path[1][2] = 1; g->path[2][1] = 1;
    g->path[0][2] = 1; g->path[2][0] = 1;
    return g;
}

/* Exemplo 2: linha
 *
 *      0 --- 1 --- 2 --- 3
 *
 *  Matriz:
 *      [0][1][2][3]
 *  [0]  0  1  0  0
 *  [1]  1  0  1  0
 *  [2]  0  1  0  1
 *  [3]  0  0  1  0
 */
grafo *exemplo_nao_direcionado_2(void) {
    grafo *g = cria_grafo(4, 0);
    g->path[0][1] = 1; g->path[1][0] = 1;
    g->path[1][2] = 1; g->path[2][1] = 1;
    g->path[2][3] = 1; g->path[3][2] = 1;
    return g;
}

/* ---------------------------------------------------------------
 *  DIRECIONADO — path[u][v] nao implica path[v][u]
 *
 *  Exemplo 1: ciclo dirigido
 *
 *      0 --> 1
 *      ^      \
 *      |       v
 *      2 <-----+
 *
 *  Matriz:
 *      [0][1][2]
 *  [0]  0  1  0
 *  [1]  0  0  1
 *  [2]  1  0  0
 * --------------------------------------------------------------- */
grafo *exemplo_direcionado_1(void) {
    grafo *g = cria_grafo(3, 0);
    g->path[0][1] = 1;
    g->path[1][2] = 1;
    g->path[2][0] = 1;
    return g;
}

/* Exemplo 2: grafo dirigido sem ciclo (DAG)
 *
 *      0 --> 1 --> 3
 *      |           ^
 *      v           |
 *      2 ----------+
 *
 *  Matriz:
 *      [0][1][2][3]
 *  [0]  0  1  1  0
 *  [1]  0  0  0  1
 *  [2]  0  0  0  1
 *  [3]  0  0  0  0
 */
grafo *exemplo_direcionado_2(void) {
    grafo *g = cria_grafo(4, 0);
    g->path[0][1] = 1;
    g->path[0][2] = 1;
    g->path[1][3] = 1;
    g->path[2][3] = 1;
    return g;
}

/* ---------------------------------------------------------------
 *  CICLICO — existe pelo menos um ciclo
 *
 *  Exemplo 1: quadrado (ciclo 0-1-2-3-0)
 *
 *      0 --- 1
 *      |     |
 *      3 --- 2
 *
 *  Matriz:
 *      [0][1][2][3]
 *  [0]  0  1  0  1
 *  [1]  1  0  1  0
 *  [2]  0  1  0  1
 *  [3]  1  0  1  0
 * --------------------------------------------------------------- */
grafo *exemplo_ciclico_1(void) {
    grafo *g = cria_grafo(4, 0);
    g->path[0][1] = 1; g->path[1][0] = 1;
    g->path[1][2] = 1; g->path[2][1] = 1;
    g->path[2][3] = 1; g->path[3][2] = 1;
    g->path[3][0] = 1; g->path[0][3] = 1;
    return g;
}

/* Exemplo 2: ciclo dirigido com auto-loop em 1
 *
 *      0 --> 1 --> 2
 *      ^     |     |
 *      |     v     |
 *      |    [1]    |
 *      +-----<-----+
 *
 *  Ciclos: 0->1->2->0  e  1->1
 *
 *  Matriz:
 *      [0][1][2]
 *  [0]  0  1  0
 *  [1]  0  1  1
 *  [2]  1  0  0
 */
grafo *exemplo_ciclico_2(void) {
    grafo *g = cria_grafo(3, 0);
    g->path[0][1] = 1;
    g->path[1][1] = 1; /* auto-loop */
    g->path[1][2] = 1;
    g->path[2][0] = 1;
    return g;
}

/* ---------------------------------------------------------------
 *  ACICLICO — nenhum ciclo existe
 *
 *  Exemplo 1: arvore com 5 vertices
 *
 *          0
 *         / \
 *        1   2
 *       / \
 *      3   4
 *
 *  Matriz:
 *      [0][1][2][3][4]
 *  [0]  0  1  1  0  0
 *  [1]  1  0  0  1  1
 *  [2]  1  0  0  0  0
 *  [3]  0  1  0  0  0
 *  [4]  0  1  0  0  0
 * --------------------------------------------------------------- */
grafo *exemplo_aciclico_1(void) {
    grafo *g = cria_grafo(5, 0);
    g->path[0][1] = 1; g->path[1][0] = 1;
    g->path[0][2] = 1; g->path[2][0] = 1;
    g->path[1][3] = 1; g->path[3][1] = 1;
    g->path[1][4] = 1; g->path[4][1] = 1;
    return g;
}

/* Exemplo 2: DAG simples
 *
 *      0 --> 1 --> 3
 *            |
 *            v
 *            2
 *
 *  Matriz:
 *      [0][1][2][3]
 *  [0]  0  1  0  0
 *  [1]  0  0  1  1
 *  [2]  0  0  0  0
 *  [3]  0  0  0  0
 */
grafo *exemplo_aciclico_2(void) {
    grafo *g = cria_grafo(4, 0);
    g->path[0][1] = 1;
    g->path[1][2] = 1;
    g->path[1][3] = 1;
    return g;
}

/* ---------------------------------------------------------------
 *  CONEXO — existe caminho entre qualquer par de vertices
 *
 *  Exemplo 1: grafo completo K3
 *
 *      0 --- 1
 *       \   /
 *        \ /
 *         2
 *
 *  Matriz:
 *      [0][1][2]
 *  [0]  0  1  1
 *  [1]  1  0  1
 *  [2]  1  1  0
 * --------------------------------------------------------------- */
grafo *exemplo_conexo_1(void) {
    grafo *g = cria_grafo(3, 0);
    g->path[0][1] = 1; g->path[1][0] = 1;
    g->path[1][2] = 1; g->path[2][1] = 1;
    g->path[0][2] = 1; g->path[2][0] = 1;
    return g;
}

/* Exemplo 2: grade 2x2
 *
 *      0 --- 1
 *      |     |
 *      2 --- 3
 *
 *  Matriz:
 *      [0][1][2][3]
 *  [0]  0  1  1  0
 *  [1]  1  0  0  1
 *  [2]  1  0  0  1
 *  [3]  0  1  1  0
 */
grafo *exemplo_conexo_2(void) {
    grafo *g = cria_grafo(4, 0);
    g->path[0][1] = 1; g->path[1][0] = 1;
    g->path[0][2] = 1; g->path[2][0] = 1;
    g->path[1][3] = 1; g->path[3][1] = 1;
    g->path[2][3] = 1; g->path[3][2] = 1;
    return g;
}

/* ---------------------------------------------------------------
 *  DESCONEXO — existem vertices sem caminho entre si
 *
 *  Exemplo 1: dois componentes separados
 *
 *      0 --- 1       2 --- 3
 *
 *  Componentes: {0,1} e {2,3}
 *
 *  Matriz:
 *      [0][1][2][3]
 *  [0]  0  1  0  0
 *  [1]  1  0  0  0
 *  [2]  0  0  0  1
 *  [3]  0  0  1  0
 * --------------------------------------------------------------- */
grafo *exemplo_desconexo_1(void) {
    grafo *g = cria_grafo(4, 0);
    g->path[0][1] = 1; g->path[1][0] = 1;
    g->path[2][3] = 1; g->path[3][2] = 1;
    return g;
}

/* Exemplo 2: tres componentes com vertice isolado
 *
 *      0 --- 1 --- 2       3 --- 4       5
 *
 *  Componentes: {0,1,2}, {3,4}, {5}
 *
 *  Matriz:
 *      [0][1][2][3][4][5]
 *  [0]  0  1  0  0  0  0
 *  [1]  1  0  1  0  0  0
 *  [2]  0  1  0  0  0  0
 *  [3]  0  0  0  0  1  0
 *  [4]  0  0  0  1  0  0
 *  [5]  0  0  0  0  0  0
 */
grafo *exemplo_desconexo_2(void) {
    grafo *g = cria_grafo(6, 0);
    g->path[0][1] = 1; g->path[1][0] = 1;
    g->path[1][2] = 1; g->path[2][1] = 1;
    g->path[3][4] = 1; g->path[4][3] = 1;
    /* vertice 5 permanece isolado */
    return g;
}
