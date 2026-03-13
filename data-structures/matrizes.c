
#include <stdio.h>
// Faça, do zero, um programa que lê uma matriz 5x4 e imprime no terminal a soma de cada uma de suas colunas.
int main() {

    int matriz[5][4];

    printf("Digite os elementos da matriz 5x4:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }


    int col1, col2, col3, col4;
    int soma[4] = {0, 0, 0, 0};

    for (int i = 0; i < 5; i++) {
        soma[0] += matriz[i][0];
        soma[1] += matriz[i][1];
        soma[2] += matriz[i][2];
        soma[3] += matriz[i][3];
    }

    printf("\nSoma das colunas:\n");

    for (int j = 0; j < 4; j++) {
        printf("Coluna %d: %d\n", j, soma[j]);
    }

    int maior = soma[0];
    int index = 0;
    
    
    return 0;
}