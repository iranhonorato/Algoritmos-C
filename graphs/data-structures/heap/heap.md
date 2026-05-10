# Heaps

## O que é

Um **heap** é uma estrutura de dados baseada em árvore binária completa que obedece a uma propriedade de ordem entre pai e filhos. É armazenado de forma eficiente em um array simples, sem necessidade de ponteiros.

## Tipos

- **Min Heap:** o pai é sempre **menor ou igual** aos filhos. O menor elemento fica na raiz.
- **Max Heap:** o pai é sempre **maior ou igual** aos filhos. O maior elemento fica na raiz.

## Propriedades

- Árvore binária **completa**: todos os níveis estão preenchidos, exceto possivelmente o último (preenchido da esquerda para a direita).
- Acesso ao elemento prioritário (mínimo ou máximo) em **O(1)** — está sempre na raiz (`array[0]`).
- Para qualquer nó no índice `i`:
  - Pai: `(i - 1) / 2`
  - Filho esquerdo: `2*i + 1`
  - Filho direito: `2*i + 2`

## Operações e complexidade

| Operação           | Complexidade |
|--------------------|-------------|
| Ver mínimo/máximo  | O(1)        |
| Inserir            | O(log n)    |
| Remover raiz       | O(log n)    |
| Build heap         | O(n)        |

## Operações de restauração (heapify)

### Heapify up — usada na inserção

O novo elemento entra no final do array e sobe comparando com o pai enquanto violar a propriedade do heap:

```
1. i = posição do novo elemento (final)
2. Enquanto i > 0 e array[i] < array[pai(i)]:
      troca array[i] com array[pai(i)]
      i = pai(i)
```

```c
void heapify_up(heap *h, int i) {
    while (i > 0 && h->array[i] < h->array[pai(i)]) {
        trocar(&h->array[i], &h->array[pai(i)]);
        i = pai(i);
    }
}
```

### Heapify down — usada na remoção

O último elemento vai para a raiz e desce trocando com o menor filho enquanto violar a propriedade:

```
1. menor = i
2. Verifica filho esquerdo e direito
3. Se algum filho é menor que o nó atual → atualiza menor
4. Se menor != i → troca e chama heapify_down recursivamente
```

```c
void heapify_down(heap *h, int i) {
    int menor = i;
    int esq = filho_esq(i);
    int dir = filho_dir(i);

    if (esq < h->size && h->array[esq] < h->array[menor]) menor = esq;
    if (dir < h->size && h->array[dir] < h->array[menor]) menor = dir;

    if (menor != i) {
        trocar(&h->array[i], &h->array[menor]);
        heapify_down(h, menor);
    }
}
```

## Inserção

```
1. Se cheio → dobra a capacidade com realloc
2. Insere no final (array[size])
3. size++
4. Heapify up a partir do último índice
```

```c
void inserir(heap *h, int val) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->array = realloc(h->array, h->capacity * sizeof(int));
    }
    h->array[h->size] = val;
    h->size++;
    heapify_up(h, h->size - 1);
}
```

## Remoção da raiz (mínimo)

```
1. Guarda o valor da raiz (array[0])
2. Move o último elemento para a raiz
3. size--
4. Heapify down a partir da raiz
5. Retorna o valor guardado
```

```c
int remover(heap *h) {
    int min = h->array[0];
    h->array[0] = h->array[h->size - 1];
    h->size--;
    heapify_down(h, 0);
    return min;
}
```

## Implementação 1 — Min Heap genérico (`heap1.c`)

```c
typedef struct Heap {
    int *array;
    int size;
    int capacity;
} heap;
```

- Armazena inteiros simples.
- Redimensiona automaticamente com `realloc` ao dobrar a capacidade.
- Funções auxiliares: `pai(i)`, `filho_esq(i)`, `filho_dir(i)`, `trocar`.
- `prioridade(h)` retorna o mínimo sem remover (`array[0]`).

## Implementação 2 — Min Heap para grafos (`heap2.c`)

```c
typedef struct Heap {
    int capacity;
    int size;
    int *vertices;
    int *pesos;
} minheap_t;
```

- Armazena **pares (vértice, peso)** em dois arrays paralelos.
- Ordenação é feita pelo **peso** (prioridade de menor custo).
- `minheap_add(min, vertice, peso)` — insere o par e faz heapify up pelo peso.
- `minheap_remove(q, *vertice, *peso)` — extrai o par de menor peso (escrita nos ponteiros passados).
- Heapify down é **iterativo** (loop `while(1)` com `break`), sem recursão.
- Projetado para uso em **algoritmos de caminho mínimo** (Dijkstra).

### Diferença entre as duas implementações

| Aspecto          | heap1.c (genérico)      | heap2.c (grafos)              |
|------------------|------------------------|-------------------------------|
| Dados            | `int` simples          | par `(vértice, peso)`         |
| Critério de ordem| valor do elemento      | peso do par                   |
| Heapify down     | recursivo              | iterativo                     |
| Redimensionamento| automático (`realloc`) | capacidade fixa               |
| Uso típico       | fila de prioridade     | Dijkstra, Prim                |

## Visualização — Min Heap

```
Inserindo: 5, 3, 8, 1

Após inserir 5:       Após inserir 3:       Após inserir 1:
      [5]                  [3]                    [1]
                          /   \                  /   \
                        [5]   [8]             [3]   [8]
                                              /
                                            [5]

array: [1, 3, 8, 5]
```

## Aplicações comuns

- **Fila de prioridade:** estrutura mais comum construída sobre um heap.
- **Heap sort:** algoritmo de ordenação O(n log n) no pior caso.
- **Algoritmo de Dijkstra:** usa min heap para sempre expandir o vértice de menor custo acumulado.
- **Algoritmo de Prim:** árvore geradora mínima usando min heap de arestas.
- **Sistemas operacionais:** escalonamento de processos por prioridade.
