// Essa linha é uma diretiva de pré-processamento.
#include <stdio.h>
// Ela diz ao pré-processador do compilador:
// “Inclua o conteúdo do arquivo stdio.h antes de compilar o programa.”


void main() {

    // Testanto output

    // %d ou %i -> Especificador de formato para números tipo inteiros
    printf("Tenho %i anos\n", 25); 

    // %f -> Especificador de formato para números tipo float
    printf("O pi pode ser aproximado como: %f\n", 3.14);

    // %c -> Especificador de formato para tipos char 
    printf("O primeiro caractere do meu nome é: %c\n", 'i');

    // %s -> Especificador de formato para tipos string
    printf("O meu nome é: %s\n", "Iran");




    // Testando input  
    int idade = 0;
    
    printf("Valor inicial da idade: %d\n", idade);
    printf("Digite um novo valor para idade:\n");
    scanf("%d", &idade);
    printf("O novo valor da idade é: %d", idade);

}





