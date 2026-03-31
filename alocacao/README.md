# Alocação de Memória em C

## Stack vs Heap

Quando um programa roda, ele tem acesso a duas regiões de memória distintas:

**Stack (Pilha)**
- Gerenciada automaticamente pelo compilador
- Cresce e encolhe conforme funções são chamadas e retornam
- Tamanho fixo e limitado (tipicamente ~1–8 MB)
- Variáveis locais vivem aqui: `int x = 10;`

**Heap**
- Gerenciada manualmente pelo programador
- Pode crescer muito (limitado pela RAM disponível)
- Alocação e liberação são controladas por você
- É aqui que o `malloc` reserva memória

```
Memória do processo:
┌─────────────┐  ← endereços altos
│    Stack    │  ← cresce para baixo
│      ↓      │
│             │
│      ↑      │
│    Heap     │  ← cresce para cima
├─────────────┤
│    BSS      │  (variáveis globais não inicializadas)
│    Data     │  (variáveis globais inicializadas)
│    Text     │  (código do programa)
└─────────────┘  ← endereços baixos
```

---

## Por que precisamos de alocação dinâmica?

Com alocação estática, o tamanho precisa ser conhecido em tempo de compilação:

```c
int array[100]; // OK — mas e se eu precisar de 101?
```

Com alocação dinâmica, você decide o tamanho em tempo de execução:

```c
int n;
scanf("%d", &n);
int *array = malloc(n * sizeof(int)); // funciona para qualquer n
```

---

## `malloc` — Memory Allocation

```c
void *malloc(size_t size);
```

Reserva `size` bytes contíguos na heap e retorna um ponteiro para o início desse bloco. Se falhar (sem memória), retorna `NULL`.

```c
int *ptr = malloc(sizeof(int));      // 4 bytes para 1 inteiro
int *arr = malloc(10 * sizeof(int)); // 40 bytes para 10 inteiros
char *s  = malloc(50 * sizeof(char));// 50 bytes para uma string
```

> O cast `(int *)` antes do `malloc` é opcional em C (mas obrigatório em C++).

**Sempre verifique o retorno:**
```c
int *ptr = malloc(sizeof(int));
if (ptr == NULL) {
    fprintf(stderr, "Erro: sem memória\n");
    exit(1);
}
```

---

## `calloc` — Cleared Allocation

```c
void *calloc(size_t n, size_t size);
```

Igual ao `malloc`, mas **inicializa todos os bytes com zero**. Útil para arrays que precisam começar zerados.

```c
int *arr = calloc(10, sizeof(int)); // 10 inteiros, todos = 0
```

---

## `realloc` — Reallocate

```c
void *realloc(void *ptr, size_t new_size);
```

Redimensiona um bloco já alocado. Pode mover o bloco para outro endereço.

```c
int *arr = malloc(5 * sizeof(int));
arr = realloc(arr, 10 * sizeof(int)); // agora tem espaço para 10
```

---

## `free` — Liberação de memória

Todo bloco alocado com `malloc`/`calloc`/`realloc` **deve** ser liberado com `free` quando não for mais necessário. Caso contrário, ocorre um **memory leak**: a memória fica ocupada até o programa encerrar.

```c
int *ptr = malloc(sizeof(int));
// ... usa ptr ...
free(ptr);
ptr = NULL; // boa prática: evita "dangling pointer"
```

**Erros comuns:**
| Erro | Descrição |
|------|-----------|
| Memory leak | Alocou e nunca liberou |
| Double free | Chamou `free` duas vezes no mesmo ponteiro |
| Use after free | Usou o ponteiro depois de liberar |
| Buffer overflow | Escreveu além do tamanho alocado |

---

## Resumo

```c
#include <stdlib.h>

int *ptr = malloc(sizeof(int));   // aloca
*ptr = 42;                         // usa
free(ptr);                         // libera
ptr = NULL;                        // limpa
```
