# Double-Ended Queue (Deque)

## O que é

Um **deque** (double-ended queue) é uma fila que permite inserções e remoções em ambas as extremidades — tanto no início (head) quanto no final (tail). É mais flexível que uma fila comum (FIFO) ou pilha (LIFO).

## Características

- **Inserção dupla:** é possível adicionar elementos no início ou no final.
- **Remoção dupla:** é possível remover elementos do início ou do final.
- **Flexibilidade:** pode ser usada como fila (FIFO), pilha (LIFO) ou estrutura mista.
- **Acesso eficiente:** O(1) para todas as operações nas extremidades.

## Operações e complexidade

| Operação          | Complexidade |
|-------------------|-------------|
| Inserir no head  | O(1)        |
| Inserir no tail   | O(1)        |
| Remover do head  | O(1)        |
| Remover do tail   | O(1)        |
| Ver primeiro      | O(1)        |
| Ver último        | O(1)        |
| Redimensionar     | O(n)        |

## Implementação Circular

O deque é implementado usando um **array circular** para eficiência:
- `head`: índice do primeiro elemento
- `tail`: índice do último elemento
- `size`: quantidade de elementos
- `capacity`: capacidade total do array

Quando o array fica cheio, é redimensionado para o dobro da capacidade.

## Operações principais

### Inserir no final (tail)
```
1. Verifica se está cheio → redimensiona se necessário
2. Move tail para a próxima posição (circular)
3. Insere o valor
4. Incrementa size
```

### Inserir no início (head)
```
1. Verifica se está cheio → redimensiona se necessário
2. Move head para a posição anterior (circular)
3. Insere o valor
4. Incrementa size
```

### Remover do início (head)
```
1. Verifica se está vazio
2. Guarda o valor
3. Move head para a próxima posição
4. Decrementa size
5. Retorna o valor
```

### Remover do final (tail)
```
1. Verifica se está vazio
2. Guarda o valor
3. Move tail para a posição anterior
4. Decrementa size
5. Retorna o valor
```

## Aplicações comuns

- **Sliding window:** problemas que precisam acessar elementos nas duas pontas.
- **Undo/Redo:** deque armazena historicamente ações.
- **Escalonamento de tarefas:** tarefas podem ser adicionadas/removidas de ambas as extremidades.
- **Processamento de buffers:** adiciona no final, processa do início.
- **Palindromo:** verifica lendo simultaneamente do início e fim.

## Representação em C

```c
typedef struct {
    int *array;
    int head;   // índice do primeiro elemento
    int tail;    // índice do último elemento
    int size;    // quantidade de elementos
    int capacity; // capacidade total
} Deque;
```
