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

| Operação        | Complexidade |
|-----------------|-------------|
| Ver mínimo/máximo | O(1)      |
| Inserir         | O(log n)    |
| Remover raiz    | O(log n)    |
| Build heap      | O(n)        |

## Operações de restauração

- **Heapify up:** usada na inserção. O novo elemento entra no final e sobe trocando com o pai enquanto violar a propriedade.
- **Heapify down:** usada na remoção. O último elemento vai para a raiz e desce trocando com o menor filho (min heap) enquanto violar a propriedade.

## Aplicações comuns

- **Fila de prioridade:** estrutura mais comum construída sobre um heap.
- **Heap sort:** algoritmo de ordenação O(n log n) no pior caso.
- **Algoritmo de Dijkstra:** caminho mínimo em grafos — usa min heap para sempre expandir o vértice mais próximo.
- **Algoritmo de Prim:** árvore geradora mínima.
- **Sistemas operacionais:** escalonamento de processos por prioridade.

## Representação em C

```c
typedef struct {
    int *array;
    int size;
    int capacity;
} Heap;
```

O heap é armazenado em um array onde a relação pai-filho é calculada por índice, eliminando a necessidade de ponteiros e tornando o acesso à memória mais eficiente (localidade de cache).
