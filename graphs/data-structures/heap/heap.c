
typedef struct Heap {
    int *array;
    int size;
    int capacity;
} heap; 



heap *criar_heap(int capacidade) {
    heap *h = malloc(sizeof(heap));

    h->array = malloc(capacidade*sizeof(int));
    h->size = 0;
    h->capacity = capacidade;

    return h;
}

void liberar_heap(heap *h) {
    free(h->array);
    free(h);
    return;
}


int prioridade(heap *h) {
    if (!h || h->size == 0) {
        printf("Heap vazio!\n");
    }
    return h->array[0];
}


void trocar(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
    return;
}


int pai(int i) { return (i - 1) / 2; }
int filho_esq(int i) { return 2 * i + 1; }
int filho_dir(int i) { return 2 * i + 2; }


// sobe um elemento até o lugar certo
void heapify_up(heap *h, int i) {
    while (i > 0 && h->array[i] < h->array[pai(i)]) {
        trocar(&h->array[i], &h->array[pai(i)]);
        i = pai(i);
    }
}

// desce um elemento até o lugar certo
void heapify_down(heap *h, int i) {
    int menor = i;
    int esq = filho_esq(i);
    int dir = filho_dir(i);

    // Verifica se algum filho é menor que o nó atual
    if (esq < h->size && h->array[esq] < h->array[menor])
        menor = esq;
    if (dir < h->size && h->array[dir] < h->array[menor])
        menor = dir;

    // Se encontrou um filho menor, troca e continua descendo
    if (menor != i) {
        trocar(&h->array[i], &h->array[menor]);
        heapify_down(h, menor);
    }
}


void inserir(heap *h, int val) {
    // Dobra a capacidade se estiver cheio
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->array = realloc(h->array, h->capacity * sizeof(int)); // bloco atual; novo tamannho
    }

    h->array[h->size] = val;  // coloca no final
    h->size++;
    heapify_up(h, h->size - 1);  // sobe até o lugar certo
}


int remover(heap *h) {
    if (heap_vazio(h)) {
        printf("Heap vazio!\n");
        return -1;
    }

    int min = h->array[0]; // guarda o mínimo
    h->array[0] = h->array[h->size - 1]; // move o último para a raiz
    h->size--;
    heapify_down(h, 0); // desce até o lugar certo

    return min;
}