# Fila Circular (Circular Queue)

## O que é

Uma **fila circular** é uma estrutura FIFO (First In, First Out) implementada sobre um array circular. Elementos entram pelo final (tail) e saem pelo início (head). O array circular evita deslocamentos desnecessários ao reutilizar posições liberadas.

## Características

- **FIFO:** o primeiro elemento inserido é o primeiro a sair.
- **Array circular:** `head` e `tail` avançam usando módulo, sem deslocar elementos.
- **Capacidade fixa:** nesta implementação, a fila não cresce — inserções em fila cheia são ignoradas.
- **Acesso O(1):** inserção e remoção em tempo constante.

## Struct

```c
typedef struct Deque {
    int *array;
    int head;      // índice do primeiro elemento
    int size;      // quantidade de elementos
    int capacity;  // capacidade total do array
} deque;
```

## Operações e complexidade

| Operação        | Complexidade |
|-----------------|-------------|
| Inserir (tail)  | O(1)        |
| Remover (head)  | O(1)        |
| Ver tamanho     | O(1)        |
| Criar           | O(1)        |
| Liberar         | O(1)        |

## Como funciona

### Inserir no final

O índice de inserção é calculado como `(head + size) % capacity`, que "dá a volta" no array quando chega ao fim:

```
1. Se cheio (size == capacity) → ignora
2. idx = (head + size) % capacity
3. array[idx] = val
4. size++
```

### Remover do início

Lê o valor em `head` e avança o ponteiro de cabeça circularmente:

```
1. Se vazio (size == 0) → retorna
2. val = array[head]
3. head = (head + 1) % capacity
4. size--
5. Se size == 0 → reseta head para 0
6. Retorna val
```

## Visualização

```
capacity = 5, head = 1, size = 3

índices:  [0] [1] [2] [3] [4]
valores:  [ ] [A] [B] [C] [ ]
               ^           ^
             head        próxima inserção em (1+3)%5 = 4
```

Após remover A:
```
índices:  [0] [1] [2] [3] [4]
valores:  [ ] [ ] [B] [C] [ ]
                   ^
                 head = 2, size = 2
```

## Funções implementadas

| Função            | Descrição                                      |
|-------------------|------------------------------------------------|
| `criar_deque`     | Aloca a fila com a capacidade especificada     |
| `liberar_deque`   | Libera memória e anula o ponteiro (`**`)       |
| `deque_size`      | Retorna o número de elementos                  |
| `inserir`         | Adiciona um elemento no final                  |
| `deletar`         | Remove e retorna o elemento do início          |
| `imprimir_deque`  | Imprime todos os elementos em ordem            |

## Diferença entre Queue e Deque

Esta implementação é uma **queue simples** (FIFO), apesar do nome `deque` na struct. Um deque completo permitiria inserção e remoção nas **duas** extremidades. Aqui só há:

- `inserir` → sempre no final (tail)
- `deletar` → sempre no início (head)

## Aplicações comuns

- **BFS (busca em largura):** a fila é a estrutura central do algoritmo.
- **Processamento em ordem:** tarefas são processadas na ordem em que chegam.
- **Buffer de dados:** produtor insere no final, consumidor retira do início.
- **Escalonamento FIFO:** sistemas operacionais para gerenciar processos.
