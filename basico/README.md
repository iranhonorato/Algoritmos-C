# Fundamentos de C

## Tipos de Dados Primitivos

Em C, cada tipo tem um tamanho fixo em memória e uma faixa de representação. O modificador `unsigned` remove o sinal, dobrando o valor máximo positivo.

| Tipo      | Tamanho | Faixa (signed)                          |
|-----------|---------|------------------------------------------|
| `char`    | 8 bits  | -128 a 127                              |
| `short`   | 16 bits | -32.768 a 32.767                        |
| `int`     | 32 bits | -2.147.483.648 a 2.147.483.647          |
| `long`    | 32/64 bits | depende da plataforma                |
| `float`   | 32 bits | ~6–7 dígitos significativos             |
| `double`  | 64 bits | ~15–16 dígitos significativos           |

Use `sizeof(tipo)` para descobrir o tamanho em bytes na sua plataforma:
```c
printf("%zu\n", sizeof(int)); // geralmente 4
```

---

## Operadores Aritméticos

| Operador | Operação          | Exemplo (`a=10, b=3`) | Resultado |
|----------|-------------------|-----------------------|-----------|
| `+`      | Adição            | `a + b`               | 13        |
| `-`      | Subtração         | `a - b`               | 7         |
| `*`      | Multiplicação     | `a * b`               | 30        |
| `/`      | Divisão           | `a / b`               | 3 (inteira!) |
| `%`      | Módulo (resto)    | `a % b`               | 1         |

> Atenção: divisão entre inteiros **descarta a parte decimal**. Para obter resultado fracionário, use `(float)a / b`.

---

## Entrada e Saída

### `printf` — saída formatada

```c
printf("formato", arg1, arg2, ...);
```

**Especificadores de formato:**

| Especificador | Tipo               |
|---------------|--------------------|
| `%d` / `%i`   | `int`              |
| `%f`          | `float` / `double` |
| `%c`          | `char`             |
| `%s`          | string (`char *`)  |
| `%p`          | ponteiro (endereço)|
| `%zu`         | `size_t`           |
| `%%`          | imprime `%` literal|

**Modificadores úteis:**
```c
printf("%.2f", 3.14159); // "3.14" — 2 casas decimais
printf("%5d", 42);       // "   42" — largura mínima 5
printf("%-5d|", 42);     // "42   |" — alinhado à esquerda
```

### `scanf` — entrada formatada

```c
int x;
scanf("%d", &x); // o & é obrigatório — passa o endereço da variável
```

> `scanf` para na leitura de strings ao encontrar espaço. Para ler uma linha inteira use `fgets`.

---

## Estruturas de Controle

### `if / else if / else`

```c
if (condicao1) {
    // ...
} else if (condicao2) {
    // ...
} else {
    // ...
}
```

**Operadores relacionais:** `==`, `!=`, `<`, `>`, `<=`, `>=`
**Operadores lógicos:** `&&` (E), `||` (OU), `!` (NÃO)

### `switch / case`

Ideal para comparar uma variável com múltiplos valores constantes:

```c
switch (variavel) {
    case 1:
        // ...
        break;  // sem break, cai no próximo case (fallthrough)
    case 2:
        // ...
        break;
    default:
        // executado se nenhum case combinar
        break;
}
```

> `switch` só funciona com tipos inteiros (`int`, `char`, `enum`). Para strings, use `strcmp`.

### Laços

```c
// for — quando se sabe o número de iterações
for (int i = 0; i < n; i++) { }

// while — enquanto condição for verdadeira
while (condicao) { }

// do-while — executa ao menos uma vez
do { } while (condicao);
```

---

## Arrays

Um array é um bloco contíguo de memória com elementos do mesmo tipo.

```c
int arr[5];              // não inicializado (lixo de memória!)
int arr[5] = {0};        // todos os elementos = 0
int arr[5] = {1,2,3};   // {1,2,3,0,0} — o restante é zerado
int arr[] = {10,20,30}; // tamanho inferido pelo compilador (3)
```

**Acesso:** índice começa em 0, vai até `n-1`.
```c
arr[0] = 10;  // primeiro elemento
arr[4] = 50;  // último elemento de arr[5]
```

**Strings** em C são arrays de `char` terminados com `'\0'` (null terminator):
```c
char nome[5] = "iran"; // {'i','r','a','n','\0'}
```

Funções úteis de `<string.h>`:

| Função | Descrição |
|--------|-----------|
| `strlen(s)` | comprimento da string (sem o `\0`) |
| `strcpy(dest, src)` | copia `src` para `dest` |
| `strcat(dest, src)` | concatena `src` ao final de `dest` |
| `strcmp(a, b)` | compara duas strings (0 = iguais) |

---

## Ponteiros

Um ponteiro é uma variável que armazena um **endereço de memória**.

```c
int valor = 42;
int *ptr = &valor;  // ptr guarda o endereço de 'valor'

printf("%d\n", valor);   // 42
printf("%p\n", ptr);     // 0x7ffd... (endereço)
printf("%d\n", *ptr);    // 42 (desreferenciamento)

*ptr = 99;               // modifica 'valor' indiretamente
printf("%d\n", valor);   // 99
```

**Ponteiro duplo (`**`):** aponta para outro ponteiro.
```c
int **pptr = &ptr; // pptr -> ptr -> valor
printf("%d\n", **pptr); // 42
```

Ponteiros são a base de: arrays dinâmicos, structs alocadas na heap, passagem por referência em funções e estruturas de dados como listas e árvores.
