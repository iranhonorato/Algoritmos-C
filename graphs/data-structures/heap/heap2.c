#include <stdlib.h>
// #include <threads.h>
#include <time.h>

typedef struct Heap {
    int capacity;
    int size;
    int *vertices;
    int *pesos;

} minheap_t;

minheap_t* minheap_create(int capacity) {
    minheap_t* min = malloc(sizeof(minheap_t));

    min->capacity = capacity;

    min->size = 0;

    min->vertices = malloc(capacity * sizeof(int));
    min->pesos = malloc(capacity * sizeof(int));

    return min;

}   

void minheap_destroy(minheap_t **min) {
    free((*min)->vertices);
    free((*min)->pesos);
    free(*min);
    *min = NULL;
}

int minheap_size(minheap_t *min) {
    return min->size;
}

void minheap_add(minheap_t *min, int vertice, int peso) {
    int i = min->size;

    min->vertices[min->size] = vertice;
    min->pesos[min->size] = peso;
    min->size++;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (min->pesos[parent] <= min->pesos[i]) break;

        // swap
        int tmpPeso    = min->pesos[parent];
        int tmpVertice = min->vertices[parent];

        min->pesos[parent]    = min->pesos[i];
        min->vertices[parent] = min->vertices[i];

        min->pesos[i]    = tmpPeso;
        min->vertices[i] = tmpVertice;

        i = parent;
    }
}


void minheap_remove(minheap_t *q, int *vertice, int *peso) {
    *vertice = q->vertices[0];
    *peso = q->pesos[0];

    q->size--;

    q->vertices[0] = q->vertices[q->size];
    q->pesos[0] = q->pesos[q->size];

    int i = 0;

    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < q->size && q->pesos[left] < q->pesos[smallest])
            smallest = left;

        if (right < q->size && q->pesos[right] < q->pesos[smallest])
            smallest = right;

        if (smallest == i) break;

        int tmpPeso = q->pesos[i];
        int tmpVertice = q->vertices[i];

        q->pesos[i] = q->pesos[smallest];
        q->vertices[i] = q->vertices[smallest];

        q->pesos[smallest] = tmpPeso;
        q->vertices[smallest] = tmpVertice;

        i = smallest;
    }
}
