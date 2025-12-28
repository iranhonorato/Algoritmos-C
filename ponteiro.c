#include <stdio.h>


int main() {

    // Declarando a variavel 'var' e armazenando o valor '25' nela
    int var = 25;

    // Conteúdo de 'var' = 25
    printf("Conteudo da variavel 'var': %d\n", var); 
    
    // Endereco onde a variavel 'var' esta alocada = 0061FF1C
    printf("Endereco de memoria onde esta armazenado o valor de 'var': %p\n", &var); 
    printf("\n");





    // Declarando o ponteiro 'ptr'
    int *ptr;

    //  Atribuindo 'ptr' ao endereco de 'var'
    ptr = &var;

    // Conteudo de 'ptr' = Endereco onde a variavel 'var' esta alocada, ou seja, 0061FF1C
    printf("Conteudo da variavel 'ptr': %p\n", ptr);

    // Conteudo presente no endereco de memoria armazenado por 'ptr'= 25 
    // (pois no enderaço 0061FF1C esta a variavel 'var' que assume o valor de 25)
    printf("Conteudo do endereco apontado pelo ponteiro 'ptr': %d\n", *ptr);

    // Endereco de memoria onde esta alocado o ponteiro 'ptr' = 0061FF18
    printf("Endereco de memoria onde esta armazenado o valor de 'ptr': %p\n", &ptr);
    printf("\n");





    // Quero mudar o conteudo de 'var' sem necessariamente utilizar 'var' 
    *ptr = 777; 
    printf("Conteudo do endereco apontado pelo ponteiro 'ptr': %d\n", *ptr);
    printf("Conteudo da variavel 'var': %d\n", var);

    return 0;
}