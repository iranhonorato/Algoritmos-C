# Structs em C

## O que é uma struct?

Uma `struct` é um tipo de dado composto que agrupa variáveis de **tipos diferentes** sob um único nome. É a forma do C de criar seus próprios tipos de dados.

```c
struct Ponto {
    int x;
    int y;
};
```

Sem struct, você precisaria gerenciar variáveis separadas (`x1, y1, x2, y2, ...`) para cada entidade. Com struct, os dados relacionados ficam juntos.

---

## Formas de Declaração

### Forma 1 — `struct` nomeada

```c
struct Aluno {
    int id;
    float nota;
};

// Para usar, é necessário escrever 'struct Aluno' sempre:
struct Aluno yuri;
yuri.id = 1;
yuri.nota = 9.5;
```

### Forma 2 — `typedef struct` (com alias)

```c
typedef struct {
    int id;
    float nota;
} Aluno;

// Agora basta usar 'Aluno' diretamente:
Aluno iran;
iran.id = 2;
```

### Forma 3 — nome original + alias (combinada)

```c
typedef struct Aluno {
    int id;
    float nota;
} Aluno;

// Permite tanto 'struct Aluno' quanto só 'Aluno'
// Necessário quando a struct referencia a si mesma (ex: listas ligadas)
```

---

## Acesso aos Membros

### Ponto `.` — para variáveis diretas (Stack)

```c
Aluno yuri;
yuri.id = 1;        // leitura/escrita direta
printf("%d", yuri.id);
```

### Seta `->` — para ponteiros (Heap)

```c
Aluno *ptr = malloc(sizeof(Aluno));
ptr->id = 2;        // equivalente a: (*ptr).id = 2
printf("%d", ptr->id);
free(ptr);
```

A seta `->` é apenas um atalho para desreferenciar o ponteiro e acessar o membro em uma única operação.

---

## Stack vs Heap com Structs

| Característica     | Sem ponteiro (`Aluno a`) | Com ponteiro (`Aluno *a`) |
|--------------------|--------------------------|---------------------------|
| Onde fica na memória | Stack                  | Heap                      |
| Acesso aos membros | `a.campo`               | `a->campo`                |
| Precisa de `malloc`? | Não                   | Sim                       |
| Precisa de `free`? | Não                     | Sim                       |
| Tamanho em tempo de compilação | Sim        | Não (dinâmico)            |
| Lifetime           | Até o fim do escopo      | Até você chamar `free`    |

```c
// Na stack — simples, mas tamanho fixo e morre com o escopo
Aluno a;
a.id = 1;

// Na heap — flexível, mas você gerencia a memória
Aluno *p = malloc(sizeof(Aluno));
p->id = 1;
free(p);
```

---

## Structs com Auto-referência (Listas Ligadas)

Structs podem conter ponteiros para si mesmas — a base de listas ligadas, árvores e outras estruturas dinâmicas:

```c
typedef struct No {
    int valor;
    struct No *proximo; // não pode usar 'No *' aqui — o alias ainda não existe
} No;
```

---

## Inicialização

```c
// Por posição (ordem dos campos)
Aluno a = {1, 9.5};

// Por nome (C99+) — mais legível e seguro
Aluno b = {.id = 2, .nota = 8.0};
```

---

## Structs como Parâmetros de Funções

Passar uma struct por valor **copia todos os campos** — pode ser caro para structs grandes. Prefira passar por ponteiro:

```c
// Por valor — cria uma cópia completa
void imprime(Aluno a) { printf("%d", a.id); }

// Por ponteiro — passa apenas o endereço (mais eficiente)
void imprime(Aluno *a) { printf("%d", a->id); }

// Por ponteiro constante — não pode modificar os dados
void imprime(const Aluno *a) { printf("%d", a->id); }
```
