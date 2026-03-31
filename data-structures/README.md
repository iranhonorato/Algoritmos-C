# Estruturas de Dados

## Matrizes (Arrays Bidimensionais)

Uma matriz em C é um array de arrays — uma grade de linhas e colunas.

```c
int matriz[3][4]; // 3 linhas, 4 colunas
```

**Na memória**, mesmo sendo bidimensional, os dados ficam em um bloco contíguo (row-major order):
```
matriz[0][0], matriz[0][1], ..., matriz[1][0], matriz[1][1], ...
```

**Iteração típica com dois laços:**
```c
for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
        printf("%d ", matriz[i][j]);
    }
}
```

---

## Árvore Binária de Busca (ABB)

### O que é uma árvore binária?

Uma árvore binária é uma estrutura hierárquica onde cada nó tem **no máximo dois filhos**: esquerdo e direito.

```
        10
       /  \
      5    15
     / \     \
    3   7    20
```

### Propriedade da ABB

Em uma Árvore Binária de **Busca**, vale a seguinte invariante para cada nó:

```
chaves da subárvore esquerda  <  nó  ≤  chaves da subárvore direita
```

Isso permite buscar, inserir e remover em **O(log n)** no caso médio.

### Estrutura do nó

```c
typedef struct Tree {
    struct Tree *left, *right, *parent;
    int key;
} TreeNode;
```

Cada nó guarda ponteiros para o filho esquerdo, filho direito, pai e a chave inteira.

---

### Operações implementadas

#### Busca — `busca_em_arvore`

Exploração recursiva: se a chave procurada for menor, vai para a esquerda; se maior, vai para a direita.

```
Buscar 7 na árvore acima:
  10 → 7 < 10, vai para esquerda
   5 → 7 > 5, vai para direita
   7 → encontrado!
```

Complexidade: **O(h)**, onde h é a altura da árvore.

#### Inserção — `insercao_node`

Desce a árvore recursivamente até encontrar uma posição vazia (`NULL`) e cria o novo nó lá.

```c
// Inserir 6:
//   10 → esq → 5 → dir → 7 → esq → NULL → insere 6
```

#### Validação — `arvore_valida`

Verifica recursivamente se cada nó respeita a propriedade da ABB (filho esquerdo < nó ≤ filho direito).

---

### Traversals (Percursos)

Existem três formas clássicas de percorrer uma árvore binária:

| Traversal   | Ordem              | Uso típico                       |
|-------------|--------------------|----------------------------------|
| In-order    | esq → raiz → dir   | Lê os valores em ordem crescente |
| Pre-order   | raiz → esq → dir   | Serialização da árvore           |
| Post-order  | esq → dir → raiz   | Liberação de memória (`free`)    |

O `array_keys` usa **in-order** para extrair as chaves em ordem crescente:
```c
void array_keys(TreeNode *root, int *idx, int *array) {
    array_keys(root->left, idx, array);   // esquerda primeiro
    array[(*idx)++] = root->key;          // depois a raiz
    array_keys(root->right, idx, array);  // depois a direita
}
```

> `idx` deve ser passado como ponteiro (`int *idx`) para que o incremento feito em chamadas recursivas seja compartilhado entre todos os níveis da recursão.

---

### Balanceamento — `abb_rebalance`

Uma ABB **desbalanceada** pode degenerar em uma lista ligada (O(n) por operação):
```
1           ← pior caso: inserção em ordem crescente
 \
  2
   \
    3
     \
      4
```

O rebalanceamento implementado usa a técnica **Day-Stout-Warren simplificada**:
1. Extrai todas as chaves em ordem crescente (`array_keys`) → array ordenado
2. Reconstrói a árvore pelo ponto médio (`build`) → garante altura mínima
3. Libera a memória da árvore antiga (`free_tree`)

```
Array: [1, 2, 3, 4, 5, 6, 7]
               4          ← ponto médio
              / \
             2   6
            / \ / \
           1  3 5  7
```

Complexidade: **O(n)** — linear no número de nós.

---

### Complexidade das operações

| Operação  | Caso médio | Pior caso (desbalanceada) |
|-----------|------------|---------------------------|
| Busca     | O(log n)   | O(n)                      |
| Inserção  | O(log n)   | O(n)                      |
| Remoção   | O(log n)   | O(n)                      |
| Balancear | O(n)       | O(n)                      |

---

### Liberação de memória — `free_tree`

Usa **post-order** para liberar os filhos antes de liberar o pai — se liberasse o pai primeiro, perderia os ponteiros para os filhos.

```c
void free_tree(TreeNode *root) {
    if (root == NULL) return;
    free_tree(root->left);   // libera subárvore esquerda
    free_tree(root->right);  // libera subárvore direita
    free(root);              // só então libera o nó atual
}
```
