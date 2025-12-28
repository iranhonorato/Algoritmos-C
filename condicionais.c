#include <stdio.h>


void main() {

    int numero;

    printf("Escolha um numero inteiro qualquer\n");
    scanf("%d", &numero);

    if (numero%2 == 0) {
        printf("O numero %d eh par\n", numero);
    } else {
        printf("O numero %d eh impar\n", numero);
    }


    int dia;
    printf("Digite um número correspondente a um dia da semana\n");
    scanf("%d", &dia); 

    switch (dia) {
    case 1:
        printf("O dia %d corresponde ao domingo", dia);
        break;
    case 2:
        printf("O dia %d corresponde à segunda", dia);
        break;

    case 3:
        printf("O dia %d corresponde à terça", dia);
        break;

    case 4:
        printf("O dia %d corresponde à quarta", dia);
        break;

    case 5: 
        printf("O dia %d corresponde à quinta", dia);
        break;

    case 6: 
        printf("O dia %d corresponde à sexta", dia);
        break;

    case 7:
        printf("O dia %d corresponde ao sabado", dia);
        break;

    default:
        printf("o dia %d não corresponde a nenhum dia da semana", dia);
        break;
    }
}


