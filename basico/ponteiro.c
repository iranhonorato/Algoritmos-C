// =============================================================================
// GUIA DEFINITIVO DE PONTEIROS EM C
// =============================================================================
// Uma variavel normal guarda um VALOR.
// Um ponteiro guarda um ENDERECO de memoria.
//
// Os tres operadores essenciais:
//   &x   -> "endereco de x"          (pega o endereco)
//   *p   -> "valor em p"             (acessa o valor no endereco)
//   int *p  -> declaracao de ponteiro (p eh um ponteiro para int)
// =============================================================================

#include <stdio.h>
#include <stdlib.h>

// =============================================================================
// 1. PONTEIRO SIMPLES
// =============================================================================
void secao_ponteiro_simples() {
    printf("\n--- 1. PONTEIRO SIMPLES ---\n");

    int x = 10;
    int *p = &x;    // p guarda o ENDERECO de x, nao o valor

    printf("x = %d\n", x);    // 10   — valor de x
    printf("p = %p\n", p);    // 0x.. — endereco que p guarda
    printf("*p = %d\n", *p);  // 10   — valor NO endereco que p guarda
    printf("&x = %p\n", &x);  // mesmo endereco que p

    // Modificar x atraves do ponteiro
    *p = 99;
    printf("x apos *p = 99: %d\n", x);  // 99 — x foi alterado via ponteiro

    // O * na DECLARACAO int *p eh so sintaxe dizendo "p eh ponteiro"
    // O * no USO *p eh o operador de dereference (acessa o valor)
}

// =============================================================================
// 2. PONTEIRO DUPLO
// =============================================================================
void secao_ponteiro_duplo() {
    printf("\n--- 2. PONTEIRO DUPLO ---\n");

    int x   = 42;
    int *p  = &x;   // p aponta para x
    int **pp = &p;  // pp aponta para p (ponteiro para ponteiro)

    // Cadeia: pp -> p -> x
    printf("x      = %d\n", x);     // 42
    printf("*p     = %d\n", *p);    // 42  (uma dereferencia)
    printf("**pp   = %d\n", **pp);  // 42  (duas dereferencias)

    **pp = 100;  // altera x atraves de dois niveis de ponteiro
    printf("x apos **pp = 100: %d\n", x);  // 100

    // Quando usar ponteiro duplo:
    //   - Matrizes dinamicas (int **matriz)
    //   - Modificar um ponteiro dentro de uma funcao
    //   - Arrays de strings (char **argv)
}

// =============================================================================
// 3. *idx++ vs (*idx)++ — PRECEDENCIA DE OPERADORES
// =============================================================================
// ++ tem precedencia MAIOR que *
// Logo: *idx++ aplica ++ em idx (o ponteiro), nao no valor
// Para alterar o valor, use parenteses: (*idx)++
// =============================================================================
void secao_precedencia() {
    printf("\n--- 3. *idx++ vs (*idx)++ ---\n");

    int arr[] = {10, 20, 30, 40};
    int *p;

    // *p++ — le o valor atual, depois move o ponteiro
    p = arr;
    printf("*p++   = %d  ", *p++);  // imprime 10, p agora aponta para arr[1]
    printf("(p agora aponta para %d)\n", *p);  // 20

    // (*p)++ — incrementa o VALOR no endereco, ponteiro nao se move
    p = arr;  // volta para arr[0]
    printf("(*p)++ = %d  ", (*p)++);  // imprime 10, arr[0] agora eh 11
    printf("(arr[0] agora vale %d)\n", arr[0]);  // 11

    // ++*p — incrementa o valor (pre-incremento), ponteiro nao se move
    p = arr;
    ++*p;
    printf("++*p fez arr[0] = %d\n", arr[0]);  // 12

    // *++p — move o ponteiro primeiro, depois le o valor
    p = arr;
    printf("*++p   = %d\n", *++p);  // 20 — pulou para arr[1]

    // REGRA: quer mudar o VALOR?  use (*p)++
    //        quer mover o PONTEIRO? use p++ ou *p++
}

// =============================================================================
// 4. MALLOC E FREE — MEMORIA DINAMICA
// =============================================================================
// malloc aloca memoria no HEAP (persiste alem do escopo da funcao)
// Retorna void* — precisa de cast ou atribuicao ao tipo correto
// Toda memoria alocada com malloc PRECISA de free
// =============================================================================
void secao_malloc_free() {
    printf("\n--- 4. MALLOC E FREE ---\n");

    // Alocando um unico inteiro
    int *num = malloc(sizeof(int));
    if (num == NULL) {
        printf("Falha na alocacao!\n");
        return;
    }
    *num = 77;
    printf("num = %d\n", *num);
    free(num);
    num = NULL;  // boa pratica: evita ponteiro dangling (aponta para lixo)

    // Alocando um array dinamico
    int n = 5;
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) return;

    for (int i = 0; i < n; i++)
        arr[i] = i * 10;  // arr[i] equivale a *(arr + i)

    printf("arr = ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // calloc — aloca E zera a memoria
    int *zeros = calloc(n, sizeof(int));  // todos os elementos serao 0
    printf("zeros[0] = %d\n", zeros[0]); // garantidamente 0

    // realloc — redimensiona um bloco ja alocado
    arr = realloc(arr, 10 * sizeof(int));  // expande de 5 para 10 elementos
    if (arr == NULL) { free(zeros); return; }
    for (int i = 5; i < 10; i++)
        arr[i] = i * 10;

    printf("arr apos realloc = ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    free(zeros);

    // ERROS CLASSICOS (nao faca isso):
    // int *p;  *p = 10;           — ponteiro nao inicializado (segfault)
    // free(p); free(p);           — double free (undefined behavior)
    // free(p); *p = 10;           — use after free (undefined behavior)
    // int *p = malloc(5); p = malloc(5); — memory leak (perdeu referencia ao 1o bloco)
}

// =============================================================================
// 5. PONTEIROS EM FUNCOES
// =============================================================================

// Passagem por VALOR — nao modifica o original
void dobro_errado(int x) {
    x = x * 2;  // muda a copia local, nao o original
}

// Passagem por REFERENCIA — modifica o original
void dobro_certo(int *x) {
    *x = *x * 2;  // acessa e modifica o valor no endereco recebido
}

// Retornando multiplos valores via ponteiros
void min_max(int *arr, int n, int *min, int *max) {
    *min = *max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

// const int* — protege o array de ser modificado dentro da funcao
void imprime_array(const int *arr, int n) {
    // *arr = 5;  — erro de compilacao: protegido por const
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Modificar um PONTEIRO dentro de uma funcao precisa de ponteiro duplo
void aloca_inteiro(int **p) {
    *p = malloc(sizeof(int));  // muda para onde p aponta
    **p = 99;
}

void secao_funcoes() {
    printf("\n--- 5. PONTEIROS EM FUNCOES ---\n");

    int n = 5;
    dobro_errado(n);
    printf("apos dobro_errado: %d\n", n);  // 5 — nao mudou

    dobro_certo(&n);
    printf("apos dobro_certo:  %d\n", n);  // 10 — mudou

    int arr[] = {3, 1, 4, 1, 5, 9};
    int mn, mx;
    min_max(arr, 6, &mn, &mx);
    printf("min=%d  max=%d\n", mn, mx);  // min=1  max=9

    printf("array: ");
    imprime_array(arr, 6);

    int *ptr = NULL;
    aloca_inteiro(&ptr);              // passa endereco do ponteiro
    printf("alocado via **p: %d\n", *ptr);  // 99
    free(ptr);
}

// =============================================================================
// 6. PONTEIROS E ARRAYS — SAO A MESMA COISA
// =============================================================================
void secao_arrays() {
    printf("\n--- 6. PONTEIROS E ARRAYS ---\n");

    int arr[] = {10, 20, 30, 40};
    int *p = arr;  // sem & porque array ja decai para ponteiro para arr[0]

    // Estas quatro expressoes sao equivalentes:
    printf("arr[2]       = %d\n", arr[2]);       // 30
    printf("*(arr + 2)   = %d\n", *(arr + 2));   // 30
    printf("p[2]         = %d\n", p[2]);          // 30
    printf("*(p + 2)     = %d\n", *(p + 2));      // 30

    // Aritmetica de ponteiros: p+1 avanca sizeof(tipo) bytes
    // Em int: avanca 4 bytes por posicao
    printf("p   = %p\n", (void*)p);
    printf("p+1 = %p\n", (void*)(p + 1));  // 4 bytes a mais
    printf("p+2 = %p\n", (void*)(p + 2));  // 8 bytes a mais

    // Percorrendo array com ponteiro
    printf("percorrendo: ");
    for (int *it = arr; it < arr + 4; it++)
        printf("%d ", *it);
    printf("\n");
}

// =============================================================================
// 7. MATRIZ DINAMICA COM PONTEIRO DUPLO
// =============================================================================
void secao_matriz() {
    printf("\n--- 7. MATRIZ DINAMICA (int**) ---\n");

    int linhas = 3, colunas = 4;

    // Passo 1: aloca array de ponteiros (cada ponteiro = uma linha)
    int **mat = malloc(linhas * sizeof(int*));

    // Passo 2: aloca cada linha individualmente
    for (int i = 0; i < linhas; i++)
        mat[i] = malloc(colunas * sizeof(int));

    // Uso normal como mat[i][j]
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            mat[i][j] = i * colunas + j;

    printf("mat[1][2] = %d\n", mat[1][2]);  // 6

    // Liberacao: ordem INVERSA da alocacao — linhas primeiro, depois o array de ponteiros
    for (int i = 0; i < linhas; i++)
        free(mat[i]);
    free(mat);
}

// =============================================================================
// 8. PONTEIRO PARA FUNCAO
// =============================================================================
int soma(int a, int b) { return a + b; }
int sub(int a, int b)  { return a - b; }

void secao_ponteiro_funcao() {
    printf("\n--- 8. PONTEIRO PARA FUNCAO ---\n");

    // Declaracao: tipo_retorno (*nome)(tipos_parametros)
    int (*op)(int, int);

    op = soma;
    printf("op(3, 4) com soma = %d\n", op(3, 4));  // 7

    op = sub;
    printf("op(3, 4) com sub  = %d\n", op(3, 4));  // -1
}

// =============================================================================
// 9. TABELA MENTAL RAPIDA
// =============================================================================
// Situacao                         | Use
// ---------------------------------|-------------------------------------
// Declarar ponteiro                | int *p
// Pegar endereco de variavel       | &x
// Acessar valor no endereco        | *p
// Modificar variavel em funcao     | f(int *p)  ->  chamar com f(&x)
// Modificar ponteiro em funcao     | f(int **p) ->  chamar com f(&ptr)
// Alocar memoria dinamica          | malloc(n * sizeof(tipo))
// Liberar memoria                  | free(p); p = NULL;
// Mover ponteiro                   | p++ ou p + n
// Modificar valor via ponteiro     | (*p)++
// Array de strings / argv          | char **
// Matriz dinamica                  | int **
// =============================================================================

int main() {
    secao_ponteiro_simples();
    secao_ponteiro_duplo();
    secao_precedencia();
    secao_malloc_free();
    secao_funcoes();
    secao_arrays();
    secao_matriz();
    secao_ponteiro_funcao();

    return 0;
}
