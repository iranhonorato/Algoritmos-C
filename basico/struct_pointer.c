// Exemplo de struct sem ponteiros
typedef struct {
    int id;
    float nota;
} Aluno;

int main() {
    // Declarando struct diretamente 
    Aluno yuri; 

    // Perceba que nesse caso o acesso aos membros se dá através de "."
    yuri.id = 1;
    yuri.nota = 10;

    // Sem Ponteiro (Pessoa p)
    // - A variável contém os dados dentro dela.
    // - É como ter o Livro na sua estante.
    // - Ocupa espaço na Stack.
    // - Acesso: p.nome
    
    // Criando apenas a "etiqueta" (ponteiro)
    Aluno *iran; 

    // Alocação de memória dinâmica
    iran = malloc(sizeof(Aluno)); // Alocando memória manualmente para esse ponteiro ou iran = (Aluno *) malloc(sizeof(ALuno))
    
    // Perceba que nesse caso o acesso aos membros se dá através de "->"  
    iran->id = 2; 
    iran->nota = 9;

    // Com Ponteiro (Pessoa *p)
    // - A variável contém um número (ex: 0x7FF1).
    // - É como ter um Post-it com o corredor e a prateleira do livro que você quer.
    // - Ocupa espaço no Heap (dinâmico).
    // - Acesso: ptr->nome

    

}