#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Deque {
    int *array;
    int head;
    int tail;
    int size;
    int capacity;
} deque;


deque *criar_deque(int capacidade) {
    deque *d = malloc(sizeof(deque));
    
    d->array = malloc(capacidade * sizeof(int));
    d->head = 0;
    d->tail = -1;
    d->size = 0;
    d->capacity = capacidade;
    
    return d;
}

void liberar_deque(deque *d) {
    free(d->array);
    free(d);
    return;
}


int deque_vazio(deque *d) {
    return d->size == 0;
}

int deque_cheio(deque *d) {
    return d->size == d->capacity;
}


// adiciona um elemento no final (tail)
void inserir_tail(deque *d, int val) {
    // Redimensiona se necessário
    if (deque_cheio(d)) {
        int *novo_array = malloc(d->capacity * 2 * sizeof(int));
        
        // Copia elementos em ordem linear
        for (int i = 0; i < d->size; i++) {
            novo_array[i] = d->array[(d->head + i) % d->capacity];
        }
        
        free(d->array);
        d->array = novo_array;
        d->head = 0;
        d->tail = d->size - 1;
        d->capacity *= 2;
    }
    
    d->tail = (d->tail + 1) % d->capacity;
    d->array[d->tail] = val;
    d->size++;
}


// adiciona um elemento no início (head)
void inserir_head(deque *d, int val) {
    // Redimensiona se necessário
    if (deque_cheio(d)) {
        int *novo_array = malloc(d->capacity * 2 * sizeof(int));
        
        // Copia elementos em ordem linear
        for (int i = 0; i < d->size; i++) {
            novo_array[i] = d->array[(d->head + i) % d->capacity];
        }
        
        free(d->array);
        d->array = novo_array;
        d->head = 0;
        d->tail = d->size - 1;
        d->capacity *= 2;
    }
    
    d->head = (d->head - 1 + d->capacity) % d->capacity;
    d->array[d->head] = val;
    d->size++;
}


// remove um elemento do final (tail)
int remover_tail(deque *d) {
    if (deque_vazio(d)) {
        printf("Deque vazio!\n");
        return -1;
    }
    
    int val = d->array[d->tail];
    d->tail = (d->tail - 1 + d->capacity) % d->capacity;
    d->size--;
    
    return val;
}


// remove um elemento do início (head)
int remover_head(deque *d) {
    if (deque_vazio(d)) {
        printf("Deque vazio!\n");
        return -1;
    }
    
    int val = d->array[d->head];
    d->head = (d->head + 1) % d->capacity;
    d->size--;
    
    return val;
}


// retorna o primeiro elemento sem remover
int primeiro(deque *d) {
    if (deque_vazio(d)) {
        printf("Deque vazio!\n");
        return -1;
    }
    
    return d->array[d->head];
}


// retorna o último elemento sem remover
int ultimo(deque *d) {
    if (deque_vazio(d)) {
        printf("Deque vazio!\n");
        return -1;
    }
    
    return d->array[d->tail];
}


// imprime todos os elementos do deque
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
