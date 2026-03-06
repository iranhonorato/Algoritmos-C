#include <stdio.h>

int ponteiros() {
    int idade = 25;
    // idade' eh uma variavel, uma variavel que armazena o valor '25'
    printf("Minha idade eh %d anos\n", idade);

    // Essa variavel, por sua vez, esta guardada em algum lugar na memoria da sua maquina
    // Esse endereco no meu caso eh: 0061FF1C e pode ser obtido fazendo '&idade'


    // Declarando o ponteiro 'ptr'
    int *ptr;

    //  Atribuindo à variavel 'ptr' ao endereco de 'idade'
    ptr = &idade;

    // Logo o conteúdo da variável 'ptr' eh: 0061FF1C
    // Para acessar o conteúdo presente nesse endeço precisamos fazer: '*ptr' -> 25

    // Observação: 
    // Como 'ptr' se trata de uma variavel, ela tambem esta armazenada em algum lugar na memoria da sua maquina
    // Para descobrir o enderço fazemos: &ptr -> 0061FF18

    // Observe o que acontece se mudarmos o conteudo da variavel 'idade': idade = 77;
    // Como o ponteiro 'ptr' armazena o endereço de memórida de 'idade', ao fazermos *ptr obteremos 77 
    // Ou se fizermos: *ptr = 99 
    // descobriremos que 'idade' agora é: 'idade' = 99

    return 0;
}

int main() {
    int valor = 42;          // O dado real (O Tesouro)
    int *ptr = &valor;       // Ponteiro simples: guarda o endereço de 'valor' (O Segurança)
    int **pptr = &ptr;       // Ponteiro duplo: guarda o endereço de 'ptr' (O Chefe)
}