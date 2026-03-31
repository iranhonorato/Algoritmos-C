# Playground — Experimentos com Ponteiros

## Aritmética de Ponteiros

Em C, um ponteiro não é apenas um endereço — você pode fazer **operações aritméticas** sobre ele. Quando você soma 1 a um ponteiro, ele avança **um elemento** (não um byte).

```c
int *ptr = ...; // suponha que ptr aponta para o endereço 1000
ptr + 1;        // aponta para 1004 (1000 + sizeof(int) = 1000 + 4)
ptr + 2;        // aponta para 1008
```

Isso funciona para qualquer tipo:
```c
char  *c = ...; c + 1; // avança 1 byte
int   *i = ...; i + 1; // avança 4 bytes
double *d = ...; d + 1; // avança 8 bytes
```

---

## Arrays e Ponteiros são equivalentes

Em C, o nome de um array **é** um ponteiro para o primeiro elemento. Por isso, as notações abaixo são completamente equivalentes:

```c
int arr[5] = {10, 20, 30, 40, 50};

arr[2]     == *(arr + 2)  // ambos retornam 30
arr[0]     == *arr        // primeiro elemento
&arr[i]    == arr + i     // endereço do i-ésimo elemento
```

A notação `arr[i]` é apenas açúcar sintático — o compilador a converte para `*(arr + i)`.

---

## Arrays Dinâmicos com `malloc`

Um array dinâmico funciona da mesma forma que um array estático em termos de acesso, mas é alocado na heap:

```c
int n = 10;
int *array = malloc(n * sizeof(int)); // bloco contíguo de 40 bytes

array[0] = 0;   // mesmo que *(array + 0)
array[5] = 10;  // mesmo que *(array + 5)

free(array);    // libera o bloco inteiro
```

**Vantagem:** o tamanho pode ser definido em tempo de execução.

---

## Visualizando a memória

```
Endereço:  1000  1004  1008  1012  1016  1020  ...
Valor:      0     2     4     6     8    10    ...
            ^                 ^
          array            array+3
          array[0]         array[3]
```

O `%p` no `printf` imprime o endereço de memória do ponteiro:
```c
printf("%p\n", array);      // ex: 0x00D32F10
printf("%d\n", *(array+5)); // valor no 6º elemento
```

---

## Por que isso importa?

Aritmética de ponteiros é a base de:
- **Percurrer arrays** eficientemente (sem copiar dados)
- **Strings em C** (que são `char *`)
- **Estruturas de dados** como listas ligadas e árvores
- **Passar arrays para funções** (sempre passados como ponteiro)

```c
// Essas duas assinaturas são idênticas para o compilador:
void func(int *arr, int n);
void func(int arr[], int n);
```
