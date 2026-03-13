#include <stdio.h>



void main() {
    // possui/ocupa 8 bits 
    // faixa de representação: -127 a 127
    char caractere = 'a';

    // possui/ocupa 16 bits 
    // faixa de representação: -32768 a 32768
    int inteiro = 10;
    short inteiro2 = 20;

    // possui/ocupa 32 bits  
    // faixa de representação: -2147483648 a 2147483648
    long inteiro3 = 30; 

    // possui/ocupa 32 bits 
    // faixa de representação: -3.4*10e(-38) a 3.4*10e(38)
    float fracionario = 3;

    // possui/ocupa 64 bits
    // faixa de representação: -1.7*10e(-308) a 1.7*10e(308)
    double fracionario2 = 3.0; 

}