#include <stdio.h> 


void arrays() {

    // Declarando um array estático (tamanho fixo)
    // Diferentemente de Java, o array não é inicializado de forma automática
    int firstArray[5]; 

    // Agora sim inicializamos o array com zeros
    int secondArray[5] = {0};
    
    // Agora inicializamos o array clerando todas as suas entradas
    int thirdArray[5] = {1, 2, 3, 4, 5}; 

    // Existe também a possibilidade de criar o array sem o tamanho para que o compilador calcule-o
    int fourthArray[] = {98, 99, 100}; 

    // Strings em C sempre terminam com \0 (null terminator), então se você não colocar uma unidade a mais no tamanho 
    // terá de lidar com um overflow
    char nome[5] = "iran";

}
