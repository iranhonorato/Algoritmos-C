#include <stdio.h>

int main() {
    int idade = 25;
    printf("Minha idade eh %d anos\n", idade);
    printf("\n");

    printf("'idade' eh uma variavel, uma variavel que armazena o valor '25'\n");
    printf("Essa variavel, por sua vez, esta guardada em algum lugar na memoria da minha maquina\n");
    printf("Esse endereco por acaso eh: %p\n", &idade);
    printf("Logo, podemos dizer que o valor %d, esta armazenado no endereco %p\n", idade, &idade);
    printf("\n");

    // Declarando o ponteiro 'ptr'
    int *ptr;

    //  Atribuindo a variavel 'ptr' ao endereco de 'idade'
    ptr = &idade;

    // Conteudo de 'ptr' = Endereco onde a variavel 'idade' esta alocada, ou seja, 0061FF0C
    printf("Declaramos um ponteiro 'ptr'\n");
    printf("Conteudo da variavel 'ptr': %p\n", ptr);
    printf("Esse ponteiro que declaramos esta armazenando o endereco de memoria onde a variavel 'idade' esta sendo guardada;\n");
    printf("Logo, esse ponteiro consegue 'apontar' qual o valor armazenado naquele endereco de memoria;\n");
    printf("Conteudo presente no endereco %p: %d", ptr, *ptr);
    printf("\n");

    printf("Como 'ptr' se trata de uma variavel, ela tambem esta armazenada em algum lugar na memoria da minha maquina\n");
    printf("Enderece onde esta armazenado a variavel 'ptr': %p\n", &ptr);
    printf("\n");

    printf("Observe o que acontece se mudarmos o conteudo da variavel 'idade'\n");
    idade = 26; 
    printf("%d eh o novo valor armazenado no endereco mesmo endereco %p", *ptr, ptr);
    printf("\n");

    printf("Outra coisa que podemos fazer eh mudar o conteudo da variavel mexendo apenas com o ponteiro\n");
    *ptr = 777;
    printf("Vamos ver o que aconteceu com a variavel 'idade'\n");
    printf("Verificando conteudo da variavel idade: %d", idade);

    return 0;
}