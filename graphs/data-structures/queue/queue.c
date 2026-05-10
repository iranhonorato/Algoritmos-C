#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Deque {
    int *array;
    int head;
    int size;
    int capacity;
} deque;


deque *criar_deque(int capacidade) {
    deque *fila = malloc(sizeof(deque));
    if (!fila) {
        return NULL;
    }
    
    fila->array = malloc(capacidade * sizeof(int));
    fila->head = 0;
    fila->size = 0;
    fila->capacity = capacidade;
    
    return fila;
}

void liberar_deque(deque **fila) {
    if (fila == NULL || *fila == NULL) return;

    free((*fila)->array);
    free((*fila));

    *fila = NULL;

    return;
}


int deque_size(deque *fila) {
    return fila->size;
}

void inserir(deque *fila, int val) {
    if (fila->size == fila->capacity) return;

    int idx = (fila->head + fila->size) % fila->capacity;

    fila->array[idx] = val;
    fila->size++; 
    return;
} 


int deletar(deque *fila) {
    if (fila->size == 0) return 0;
    
    int val = fila->array[fila->head];

    int idx = (fila->head + 1) % fila->capacity;
    
    fila->head = idx;
    fila->size--;

    if (fila->size == 0) {
        fila->head = 0;
    }

    return val;
} 



void imprimir_deque(deque *d) {
    if (deque_vazio(d)) {
        printf("Deque vazio!\n");
        return;
    }
    
    printf("Deque: [");
    for (int i = 0; i < d->size; i++) {
        printf("%d", d->array[(d->head + i) % d->capacity]);
        if (i < d->size - 1) printf(", ");
    }
    printf("]\n");
}
