#include <stdio.h>
#include <stdlib.h>

// O que é o malloc?
// O nome malloc vem de Memory Allocation (Alocação de Memória). 
// Ele é uma função que permite que o seu programa peça um pedaço de memória RAM para o computador 
// enquanto ele está rodando.

// Por que não usamos o jeito normal?
// Normalmente, quando você cria uma variável como
// int idade;, 
// o C reserva o espaço automaticamente.
// Isso se chama Alocação Estática. 
//O problema é que o tamanho desse espaço fica "travado" desde o início. 
//Se você precisar de mais espaço depois, já era.

// O malloc permite a Alocação Dinâmica: você define o tamanho do espaço "no improviso".

int main() {

    int *ptr; // Criamos um ponteiro (uma etiqueta com o endereço)
    char *c; 

    // Pedindo espaço para 1 número inteiro
    ptr = (int *) malloc(sizeof(int));
    char *c = malloc(sizeof(c));

    // Para usar o malloc precisamos de 3 informações:
    // 1) Ponteiro: int *ptr; (Para anotar o endereço desse lugar)
    // 2) Quanto de memória você quer: sizeof(int) (4 bytes nesse caso)
    // 3) O que eu vou guardar lá: int 

    // Liberação do espaço que estava alocado antes
    free(ptr);
    free(c);
 
    return 0;
}